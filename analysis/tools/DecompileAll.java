// Ghidra headless script to decompile all functions in a DLL
// @category Analysis
// @author Claude

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;

import java.io.*;
import java.util.*;

public class DecompileAll extends GhidraScript {

    @Override
    public void run() throws Exception {
        String outputDir = "C:\\SourceControl\\dirapi\\ghidra_output";
        new File(outputDir).mkdirs();

        Program program = currentProgram;
        FunctionManager funcMgr = program.getFunctionManager();

        // Setup decompiler
        DecompInterface decomp = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decomp.setOptions(options);
        decomp.openProgram(program);

        // 1. Export all decompiled functions
        PrintWriter funcWriter = new PrintWriter(new FileWriter(outputDir + "\\decompiled_functions.c"));
        funcWriter.println("// Decompiled from: dirapi.dll");
        funcWriter.println("// Total functions: " + getFunctionCount(funcMgr));
        funcWriter.println();

        int count = 0;
        int total = getFunctionCount(funcMgr);
        FunctionIterator funcs = funcMgr.getFunctions(true);

        while (funcs.hasNext() && !monitor.isCancelled()) {
            Function func = funcs.next();
            count++;

            if (count % 100 == 0) {
                println("Decompiling function " + count + "/" + total + ": " + func.getName());
            }

            DecompileResults results = decomp.decompileFunction(func, 60, monitor);

            funcWriter.println("// ============================================================");
            funcWriter.println("// Function: " + func.getName());
            funcWriter.println("// Address: " + func.getEntryPoint().toString());
            funcWriter.println("// Size: " + func.getBody().getNumAddresses() + " bytes");

            if (func.isThunk()) {
                funcWriter.println("// THUNK -> " + func.getThunkedFunction(true).getName());
            }

            // Parameter info
            Parameter[] params = func.getParameters();
            if (params.length > 0) {
                funcWriter.print("// Params: ");
                for (int i = 0; i < params.length; i++) {
                    if (i > 0) funcWriter.print(", ");
                    funcWriter.print(params[i].getDataType().getName() + " " + params[i].getName());
                }
                funcWriter.println();
            }

            funcWriter.println("// Return: " + func.getReturnType().getName());
            funcWriter.println("// Calling convention: " + func.getCallingConventionName());
            funcWriter.println("// ============================================================");

            if (results != null && results.decompileCompleted()) {
                String decompiled = results.getDecompiledFunction().getC();
                funcWriter.println(decompiled);
            } else {
                funcWriter.println("// DECOMPILATION FAILED");
                if (results != null) {
                    funcWriter.println("// Error: " + results.getErrorMessage());
                }
            }
            funcWriter.println();
        }

        funcWriter.close();
        println("Wrote " + count + " decompiled functions");

        // 2. Export exports table
        PrintWriter exportWriter = new PrintWriter(new FileWriter(outputDir + "\\exports.txt"));
        SymbolTable symTable = program.getSymbolTable();
        SymbolIterator symbols = symTable.getAllSymbols(true);

        exportWriter.println("// Exports from dirapi.dll");
        while (symbols.hasNext()) {
            Symbol sym = symbols.next();
            if (sym.isExternalEntryPoint()) {
                Function func = funcMgr.getFunctionAt(sym.getAddress());
                String signature = func != null ? func.getSignature().getPrototypeString() : "unknown";
                exportWriter.println(sym.getName() + " @ " + sym.getAddress() + " : " + signature);
            }
        }
        exportWriter.close();

        // 3. Export imports table
        PrintWriter importWriter = new PrintWriter(new FileWriter(outputDir + "\\imports.txt"));
        importWriter.println("// Imports used by dirapi.dll");
        ExternalManager extMgr = program.getExternalManager();
        for (String libName : extMgr.getExternalLibraryNames()) {
            importWriter.println("\n// " + libName);
            SymbolIterator extSyms = symTable.getSymbols(libName);
            // Use external locations instead
        }

        // Alternative: iterate all external references
        symbols = symTable.getAllSymbols(true);
        String currentLib = "";
        while (symbols.hasNext()) {
            Symbol sym = symbols.next();
            if (sym.isExternal()) {
                String[] path = sym.getPath();
                if (path.length > 1) {
                    String lib = path[0];
                    if (!lib.equals(currentLib)) {
                        importWriter.println("\n// === " + lib + " ===");
                        currentLib = lib;
                    }
                    importWriter.println("  " + sym.getName() + " @ " + sym.getAddress());
                }
            }
        }
        importWriter.close();

        // 4. Export data types
        PrintWriter typeWriter = new PrintWriter(new FileWriter(outputDir + "\\data_types.txt"));
        typeWriter.println("// Data types recovered from dirapi.dll");
        DataTypeManager dtm = program.getDataTypeManager();

        Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType dt = dtIter.next();
            if (dt instanceof Structure) {
                Structure struct = (Structure) dt;
                typeWriter.println("\nstruct " + struct.getName() + " { // size: 0x" +
                    Integer.toHexString(struct.getLength()));
                for (DataTypeComponent comp : struct.getComponents()) {
                    typeWriter.println("    " + comp.getDataType().getName() + " " +
                        (comp.getFieldName() != null ? comp.getFieldName() : "field_0x" +
                        Integer.toHexString(comp.getOffset())) +
                        "; // offset 0x" + Integer.toHexString(comp.getOffset()));
                }
                typeWriter.println("};");
            } else if (dt instanceof ghidra.program.model.data.Enum) {
                ghidra.program.model.data.Enum enumDt = (ghidra.program.model.data.Enum) dt;
                typeWriter.println("\nenum " + enumDt.getName() + " {");
                for (String name : enumDt.getNames()) {
                    typeWriter.println("    " + name + " = " + enumDt.getValue(name) + ",");
                }
                typeWriter.println("};");
            } else if (dt instanceof TypeDef) {
                TypeDef td = (TypeDef) dt;
                typeWriter.println("typedef " + td.getBaseDataType().getName() + " " + td.getName() + ";");
            }
        }
        typeWriter.close();

        // 5. Export string references
        PrintWriter strWriter = new PrintWriter(new FileWriter(outputDir + "\\strings.txt"));
        strWriter.println("// String references found in dirapi.dll");
        DataIterator dataIter = program.getListing().getDefinedData(true);
        while (dataIter.hasNext()) {
            Data data = dataIter.next();
            if (data.getDataType() instanceof StringDataType ||
                data.getDataType().getName().contains("string") ||
                data.getDataType().getName().contains("char")) {
                Object value = data.getValue();
                if (value != null) {
                    strWriter.println(data.getAddress() + ": " + value.toString());
                }
            }
        }
        strWriter.close();

        decomp.dispose();
        println("Decompilation complete! Output in: " + outputDir);
    }

    private int getFunctionCount(FunctionManager funcMgr) {
        int count = 0;
        FunctionIterator iter = funcMgr.getFunctions(true);
        while (iter.hasNext()) {
            iter.next();
            count++;
        }
        return count;
    }
}

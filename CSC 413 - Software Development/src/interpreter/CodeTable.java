/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;

import java.util.*;

/**
 *
 * @author Parker
 */

/*
CodeTable.java holds all of the ByteCodes in a HashMap. When the program is ran, ByteCodeLoader's loadCodes() method is ran, 
which calls CodeTable's get() method to turn the next read code into a string, then place that code into the Program object of 
Interpreter .java to be output. Eg, ByteCodeLoader reads HALT, goes to get() with String HALT in mind, then that instance 
of HALT is stored into the Program object created in Interpreter.java.
*/
public class CodeTable {
    static HashMap byteCode = new HashMap();
    
    public static String get(String code) {
        return byteCode.get(code).toString();
    }
    
    public static void init() {
        byteCode.put("ARGS", "ArgsCode");
        byteCode.put("BOP", "BopCode");
        byteCode.put("CALL", "CallCode");
        byteCode.put("FALSEBRANCH", "FalseBranchCode");
        byteCode.put("GOTO", "GotoCode");
        byteCode.put("HALT", "HaltCode");
        byteCode.put("LABEL", "LabelCode");
        byteCode.put("LIT", "LitCode");
        byteCode.put("LOAD", "LoadCode");
        byteCode.put("POP", "PopCode");
        byteCode.put("READ", "ReadCode");
        byteCode.put("RETURN", "ReturnCode");
        byteCode.put("STORE", "StoreCode");
        byteCode.put("WRITE", "WriteCode");
        byteCode.put("DUMP", "DumpCode");
    }
}

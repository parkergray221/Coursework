/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;

import interpreter.bytecodes.ByteCode;
import java.io.*;
import java.util.*;

/**
 *
 * @author Parker
 */

/*
ByteCodeLoader.java loads bytecodes from the file to the VirtualMachine. When it reads a bytecode, it gets the class of that
bytecode from CodeTable and an instance of that byteCode is created.
*/
public class ByteCodeLoader extends Object{
    private final BufferedReader byteCodeReader;
    
    public ByteCodeLoader(String programFile) throws IOException {
        byteCodeReader = new BufferedReader(new FileReader(programFile));
    }
    
    public Program loadCodes() throws ClassNotFoundException,
            InstantiationException, IllegalAccessException, IOException {

        Program program = new Program();
        ArrayList<String> args = new ArrayList<String>();
        CodeTable.init();
        String readLine = byteCodeReader.readLine();
        
        while(readLine != null) {
            StringTokenizer tok = new StringTokenizer(readLine);
            args.clear();
            String codeClass = CodeTable.get(tok.nextToken());
            while(tok.hasMoreTokens()) {
                args.add(tok.nextToken());
            }
            ByteCode byteCode = (ByteCode)(Class.forName("interpreter.bytecodes."
                                           + codeClass).newInstance());
            byteCode.init(args);
            program.addCode(byteCode);
            readLine = byteCodeReader.readLine();
        }
        program.resolveAddresses();
        return program;
    }
}

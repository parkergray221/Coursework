/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.bytecodes;

import interpreter.VirtualMachine;
import java.util.*;

/**
 *
 * @author Parker
 */
public class LitCode extends ByteCode {
    int n;
    String id = "";
    
    public void init(ArrayList<String> args) {
        n = Integer.parseInt(args.get(0));
        if(args.size() > 1){
            id = args.get(args.size() - 1);
        }
    }
    
    public void execute(VirtualMachine vm) {
        vm.vmPush(n);
    }
    
    public String toString() {
        return "LIT " + n + " " + id;
    }

    public int getNum() {
        return n;
    }
    
    public String getID() {
        return id;
    }
}

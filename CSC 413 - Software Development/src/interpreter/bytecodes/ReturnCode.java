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
public class ReturnCode extends ByteCode {
    String funcname = "";
    int topValue;
    
    public void init(ArrayList<String> args) {
        if(!args.isEmpty()) {
            funcname = args.get(0);
        }
    }
    
    public void execute(VirtualMachine vm) {
        vm.vmPopFrame();
        vm.setPC(vm.popRetAddrs());
        topValue = vm.vmPeek();
    }
    
    public String toString() {
        return "RETURN " + funcname;
    }
}

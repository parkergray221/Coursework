/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.bytecodes;
import java.util.*;
import interpreter.VirtualMachine;

/**
 *
 * @author Parker
 */
public class ArgsCode extends ByteCode {
    int n;
   
    public void init(ArrayList<String> args) {
        n = Integer.parseInt(args.get(0));
    }
    
    public void execute(VirtualMachine vm) {
        vm.vmFrameAt(n);
    }
    
    public String toString() {
        return "ARGS " + n;
    }
}

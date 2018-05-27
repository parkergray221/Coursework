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
public class StoreCode extends ByteCode {
        int n;
    String id = "";
   
    public void init(ArrayList<String> args) {
        if(args.size() == 1) {
            n = Integer.parseInt(args.get(0));
        } else {
            id = args.get(args.size() - 1);
            n = Integer.parseInt(args.get(0));
        }
    }

    public void execute(VirtualMachine vm) {
        vm.vmStore(n);
    }

    public String toString() {
        return "STORE " + n + " " + id;
    }
}

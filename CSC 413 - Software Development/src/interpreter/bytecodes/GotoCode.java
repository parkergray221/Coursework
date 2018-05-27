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
public class GotoCode extends ByteCode {
    String label = "";
    int targetAddress;
    
    public void init(ArrayList<String> args) {
        label = (String)args.get(0);
    }
    
    public void execute(VirtualMachine vm) {
        vm.setPC(targetAddress);
    }
    
    public String toString() {
        return "GOTO " + label;
    }
    
    public void setLabel(String newLabel) {
        label = newLabel;
    }
    
    public String getLabel() {
        return label;
    }
    
    public int getTargetAddress() {
        return targetAddress;
    }
    
    public void setTargetAddress(int newAddress) {
        targetAddress = newAddress;
    }
}

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
public class LabelCode extends ByteCode {
    String label;
    
    public void init(ArrayList<String> args) {
        label = (String)args.get(0);
    }
    
    public void execute(VirtualMachine vm) {}
    
    public String toString() {
        return "LABEL " + label;
    }
    
    public String getLabel() {
        return label;
    }
}

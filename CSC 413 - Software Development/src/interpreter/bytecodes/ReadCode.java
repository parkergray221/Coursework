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
public class ReadCode extends ByteCode {
    Scanner scanner = new Scanner(System.in);
    
    public void init(ArrayList<String> args) {}
    
    public void execute(VirtualMachine vm) {
        System.out.print("Enter a number: ");
        int userInputer = scanner.nextInt();
        vm.vmPush(userInputer);
    }
    
    public String toString() {
        return "READ";
    }

}

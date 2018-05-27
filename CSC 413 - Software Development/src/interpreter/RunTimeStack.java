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
RunTimeStack.java's job is to demonstrate what is on the stack when running the program. It uses dump() to iterate through a 
program and print out values that it uncovers like the value one might assign to an integer i or j. It contains methods typical
of a stack- push, pop, peek, among others.
*/
public class RunTimeStack {
    private final Stack<Integer> framePointers;
    private final ArrayList<Integer> runStack;
    
    public RunTimeStack() {
        framePointers = new Stack<Integer>();
        runStack = new ArrayList<Integer>();
        framePointers.push(0);
    }
    
    public void dump() {
        Iterator iterator = framePointers.iterator();
        int frameCount = (Integer)iterator.next();
        
        if(iterator.hasNext()) {
            frameCount = (Integer)iterator.next();
        }
        
        System.out.print("[");
        if(!runStack.isEmpty()) {
            System.out.print(runStack.get(0));
        }
        
        for(int i = 1; i < runStack.size(); i++) {
            if(i == frameCount) {
                System.out.print("] [" + runStack.get(i));
                if(iterator.hasNext()){
                    frameCount = (Integer)iterator.next();
                }
            }else
                System.out.print("," + runStack.get(i));
        }
        System.out.println("]");
    }
    
    public int getValue(int n) {
        return runStack.get(n);
    }
    
    public int peek() {
        return runStack.get(runStack.size() - 1);
    }
    
    public int peekFrame() {
        return framePointers.peek();
    }
    
    public int pop() {
        int pop = runStack.get(runStack.size() - 1);
        runStack.remove(runStack.size() - 1);
        return pop;
    }
    
    public int push(int i) {
        runStack.add(i);
        return i;
    }
    
    public void newFrameAt(int offset) {
        framePointers.push(runStack.size() - offset);
    }
    
    public void popFrame() {
        int returnValue = runStack.get(runStack.size() - 1);
        while(runStack.size() != framePointers.peek()) {
            runStack.remove(runStack.size() - 1 );
        }
        framePointers.pop();
        runStack.add(returnValue);
    }
    
    public int store(int offset) {
        int storeValue = runStack.get(runStack.size() - 1);
        runStack.remove(runStack.size() - 1);
        runStack.set(framePointers.peek() + offset, storeValue);
        return storeValue;
    }
    
    public int load(int offset) {
        int loadValue = runStack.get(framePointers.peek() + offset);
        runStack.add(loadValue);
        return loadValue;
    }
    
    public Integer push(Integer i) {
        runStack.add(i);
        return i;
    }

}

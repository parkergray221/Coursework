/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ast;

/**
 *
 * @author Parker
 */
import visitor.*;

public class SemicolonTree extends AST {

    public SemicolonTree() {
    }

    public Object accept(ASTVisitor v) {
        return v.visitSemicolonTree(this);
    }

}


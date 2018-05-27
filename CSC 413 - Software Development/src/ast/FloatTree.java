/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ast;

import lexer.Symbol;
import lexer.Token;
import visitor.*;

/**
 *
 * @author Parker
 */
public class FloatTree extends AST {
    private Symbol symbol;
    
    public FloatTree(Token tok) {
        this.symbol = tok.getSymbol();
    }

    public Object accept(ASTVisitor v) {
        return v.visitIntTree(this);
    }

    public Symbol getSymbol() {
        return symbol;
    }
}

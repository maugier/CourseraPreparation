/* Generated By:JJTree: Do not edit this line. ASTShiftExpression.java */

package net.sourceforge.pmd.lang.java.ast;

public class ASTShiftExpression extends AbstractJavaTypeNode {
    public ASTShiftExpression(int id) {
        super(id);
    }

    public ASTShiftExpression(JavaParser p, int id) {
        super(p, id);
    }


    /**
     * Accept the visitor. *
     */
    public Object jjtAccept(JavaParserVisitor visitor, Object data) {
        return visitor.visit(this, data);
    }
}

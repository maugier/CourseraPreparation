/* Generated By:JJTree: Do not edit this line. ASTLabeledStatement.java */

package net.sourceforge.pmd.lang.java.ast;

public class ASTLabeledStatement extends AbstractJavaNode {
    public ASTLabeledStatement(int id) {
        super(id);
    }

    public ASTLabeledStatement(JavaParser p, int id) {
        super(p, id);
    }

    public Object jjtAccept(JavaParserVisitor visitor, Object data) {
        return visitor.visit(this, data);
    }

}

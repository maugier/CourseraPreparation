/* Generated By:JJTree: Do not edit this line. ASTNormalAnnotation.java */

package net.sourceforge.pmd.lang.java.ast;

public class ASTNormalAnnotation extends AbstractJavaTypeNode {
    public ASTNormalAnnotation(int id) {
        super(id);
    }

    public ASTNormalAnnotation(JavaParser p, int id) {
        super(p, id);
    }


    /**
     * Accept the visitor. *
     */
    public Object jjtAccept(JavaParserVisitor visitor, Object data) {
        return visitor.visit(this, data);
    }
}

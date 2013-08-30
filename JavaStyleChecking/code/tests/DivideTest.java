import static org.junit.Assert.*;
import org.junit.Test;
import junit.framework.TestCase;


public class DivideTest extends TestCase {

	Divide oDivide = new Divide(); 
	
	public void test1() {
		
		assertTrue(1 == (int) oDivide.Run(1, 1));
	}
	
	public void test2() {
		
		assertTrue(0 == (int) oDivide.Run(0, 1));
	}
	
	public void test3() {
		
		assertTrue(10 == (int) oDivide.Run(10, 1));
	}
	
	public void test4() {
		
		assertTrue(5 == (int) oDivide.Run(10, 2));
	}
	
	public void test5() {
		
		assertTrue(0.5 == oDivide.Run(5, 10));
	}

}

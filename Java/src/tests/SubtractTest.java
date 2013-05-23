import static org.junit.Assert.*;
import org.junit.Test;
import junit.framework.TestCase;


public class SubtractTest extends TestCase {

	Subtract oSubtract = new Subtract(); 
	
	public void test1() {
		
		assertTrue(0 == (int) oSubtract.Run(1, 1));
	}
	
	public void test2() {
		
		assertTrue(-1 == (int) oSubtract.Run(0, 1));
	}
	
	public void test3() {
		
		assertTrue(1 == (int) oSubtract.Run(1, 0));
	}
	
	public void test4() {
		
		assertTrue(20 == (int) oSubtract.Run(30, 10));
	}
	
	public void test5() {
		
		assertTrue(10 == oSubtract.Run(20, 10));
	}
}

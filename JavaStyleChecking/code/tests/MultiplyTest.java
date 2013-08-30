import static org.junit.Assert.*;
import org.junit.Test;
import junit.framework.TestCase;

public class MultiplyTest extends TestCase {

	Multiply oMultiply = new Multiply(); 
	
	public void test1() {
		
		assertTrue(1 == (int) oMultiply.Run(1, 1));
	}
	
	public void test2() {
		
		assertTrue(0 == (int) oMultiply.Run(0, 1));
	}
	
	public void test3() {
		
		assertTrue(10 == (int) oMultiply.Run(10, 1));
	}
	
	public void test4() {
		
		assertTrue(20 == (int) oMultiply.Run(10, 2));
	}
	
	public void test5() {
		
		assertTrue(50 == oMultiply.Run(5, 10));
	}
}

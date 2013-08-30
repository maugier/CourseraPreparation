import static org.junit.Assert.*;
import org.junit.Test;
import junit.framework.TestCase;

public class AddTest extends TestCase {
	
	public void test1() {
		
		Add oAdd = new Add(); 
		assertTrue(10 == (int) oAdd.Run(5, 5));
	}
	
	public void test2() {
		
		Add oAdd = new Add(); 
		assertTrue(-10 == (int) oAdd.Run(-5, -5));
	}
	
	public void test3() {
		
		Add oAdd = new Add(); 
		assertTrue(0 == (int) oAdd.Run(0, 0));
	}
	
	public void test4() {
		
		Add oAdd = new Add(); 
		assertTrue(-5 == (int) oAdd.Run(10, -5));
	}
	
	public void test5() {
		
		Add oAdd = new Add(); 
		assertTrue(-5 == (int) oAdd.Run(-5, 10));
	}

}

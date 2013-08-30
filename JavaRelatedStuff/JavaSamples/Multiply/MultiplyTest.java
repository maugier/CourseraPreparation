import static org.junit.Assert.*;
import org.junit.Test;
import junit.framework.TestCase;
import java.io.PrintStream;
import java.io.ByteArrayOutputStream;

public class MultiplyTest extends TestCase {

	Multiply oMultiply = new Multiply(); 
	
	public void test1() {
		
		assertTrue(1 == (int) oMultiply.Run(1, 1));
	}
	
	public void test2()
	{
		// Byte array output stream 
		ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		
		// Print stream 
		PrintStream printStream = new PrintStream(outputStream);
		
		// Adjusting the print stream
		System.setOut(printStream);
		
		// Execute the function 
		oMultiply.PrintHello();

		// Be careful of the LineSeparator with println
		String newLine = System.getProperty("line.separator");
		if (newLine == null) 
			newLine = "\n";
		
		// Expected String 
		String expected = "Helloo" + newLine;
				
		assertEquals("First Assert", expected, outputStream.toString());
	}
}



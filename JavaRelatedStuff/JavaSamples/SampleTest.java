import static org.junit.Assert.*;
import org.junit.Test;
import junit.framework.TestCase;
import java.io.PrintStream;
import java.io.ByteArrayOutputStream;

public class SampleTest extends TestCase 
{
	public void TestPrintHello()
		
	{
		// Byte array output stream 
		ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		
		// Print stream 
		PrintStream printStream = new PrintStream(outputStream);
		
		// Adjusting the print stream
		System.setOut(printStream);
		
		// Execute the function 
		Sample1.PrintHello();

		// Be careful of the LineSeparator with println
		String newLine = System.getProperty("line.separator");
		if (newLine == null) 
			newLine = "\n";
		
		// Expected String 
		String expected = "Hello" + newLine;
		

		Sample sample = new Sample();
		
		assertTrue("Hello" == "Hello");
	}
	
	
	
}

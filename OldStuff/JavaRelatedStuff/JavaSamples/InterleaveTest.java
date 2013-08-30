import static org.junit.Assert.*;
import org.junit.Test;
import junit.framework.TestCase;
import java.io.PrintStream;
import java.io.ByteArrayOutputStream;

public class InterleaveTest extends TestCase {
	
	Interleave iInterleave = new Interleave();
	
	public void testPrintEx()
	{
		// Byte array output stream 
		ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		
		// Print stream 
		PrintStream printStream = new PrintStream(outputStream);
		
		// Adjusting the print stream
		System.setOut(printStream);
		
		// Execute the function 
		iInterleave.PrintExNumber();

		// Be careful of the LineSeparator with println
		String newLine = System.getProperty("line.separator");
		if (newLine == null) 
			newLine = "\n";
		
		// Expected String 
		String expected = "Ex1" + newLine;
				
		assertEquals("First Assert", expected, outputStream.toString());
	}
	
	public void testTable1()
	{
		// Byte array output stream 
		ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		
		// Print stream 
		PrintStream printStream = new PrintStream(outputStream);
		
		// Adjusting the print stream
		System.setOut(printStream);
		
		// Execute the function 
		iInterleave.printTable1();

		// Be careful of the LineSeparator with println
		String newLine = System.getProperty("line.separator");
		if (newLine == null) 
			newLine = "\n";
		
		// Expected String 
		String expected = "1 7 6 ";
				
		assertEquals("First Assert", expected, outputStream.toString());
	}
	
	public void testTable2()
	{
		// Execute the parsing function
		String[] args = {"3", "1", "4"};
		iInterleave.ReadArgumentsIntoArray(args);
		
		// Byte array output stream 
		ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		
		// Print stream 
		PrintStream printStream = new PrintStream(outputStream);
		
		// Adjusting the print stream
		System.setOut(printStream);
		
		// Execute the function 
		iInterleave.printTable2();

		// Be careful of the LineSeparator with println
		String newLine = System.getProperty("line.separator");
		if (newLine == null) 
			newLine = "\n";
		
		// Expected String 
		String expected = "3 1 4 ";
				
		assertEquals("First Assert", expected, outputStream.toString());
	}
	
	public void testTableInterleaved()
	{
		// Execute the parsing function
		String[] args = {"1", "3", "7", "1", "6", "4"};
		iInterleave.ReadArgumentsIntoArray(args);
		
		// Interleave tables 
		iInterleave.InterleaveTables(); 
		
		// Byte array output stream 
		ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		
		// Print stream 
		PrintStream printStream = new PrintStream(outputStream);
		
		// Adjusting the print stream
		System.setOut(printStream);
		
		// Execute the function 
		iInterleave.printInterleavedTable();

		// Be careful of the LineSeparator with println
		String newLine = System.getProperty("line.separator");
		if (newLine == null) 
			newLine = "\n";
		
		// Expected String 
		String expected = "1 3 7 1 6 4 ";
				
		assertEquals("First Assert", expected, outputStream.toString());
	}
}

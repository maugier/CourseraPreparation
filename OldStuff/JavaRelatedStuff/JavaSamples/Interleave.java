/**
 * Some modifications in the statement of the exercise: 
 * 1. The values of the second table will be entered from the keyboard. 
 * 1M. The value of the second table will be provided from the command arguments 
 * 2. The printing functions of the tables should be named as follow 
 * 	printTable1(), printTable2() and printInterleavedTable() "in french"
 * 3. The printing of the table contents should be on the same line. 
 */

public class Interleave
{
	public static void PrintExNumber()
	{
		System.out.println("Ex1");
	}
	
	// Arrays (Tables) 
	static int[] table1 = {1, 7, 6};
	
	// The second table should be the same size of the first table 
	static int[] table2 = new int[3];
	static int[] table3 = new int[6];
	
	public static void printTable1()
	{
		for (int i = 0; i < table1.length; i++)
		{
			System.out.print(table1[i] + " ");
		}
	}
	
	public static void printTable2()
	{
		for (int i = 0; i < table2.length; i++)
		{
			System.out.print(table2[i] + " ");
		}
	}
	
	public static void printInterleavedTable()
	{
		for (int i = 0; i < table3.length; i++)
		{
			System.out.print(table3[i] + " ");
		}
	}
	
	public static void ReadArgumentsIntoArray(String[] args)
	{
		// Parse the values of the second table 
		if(args.length == 3)
		{
			for (int i = 0; i < args.length; i++)
			{
				table2[i] = Integer.parseInt(args[i]);
			}
		}	
	}
	
	public static void InterleaveTables()
	{
		// Interleave the 2 arrays 
		for (int i = 0; i < table3.length / 2; i++)
		{
			// Even index 
			table3[2 * i] = table1[i];
			
			// Odd index 
			table3[2 * i + 1] = table2[i];
		}
	}
	
	public static void main(String[] args)
	{
		// Read the arguments 
		ReadArgumentsIntoArray(args);
		
		// Interleave the arrays
		InterleaveTables();
		
		// Print the values of the first table 
		System.out.println("\nTable 1");
		printTable1();
		
		// Print the values of the second table
		System.out.println("\nTable 2"); 
		printTable2(); 
		
		// Print the values of the interleaved table
		System.out.println("\nInterleaved Table"); 
		printInterleavedTable();
		System.out.println("\n"); 
	}
	
	
}

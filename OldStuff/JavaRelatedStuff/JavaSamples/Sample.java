public class Sample
{	
	
	// Create a public array and print it 
	static int [] publicArray = {10, 20, 30};
	public static void printPublicArray()
	{
		for (int i = 0; i < publicArray.length; i++)
		{
			System.out.println(publicArray[i]);
		}
	}
		
	// Print an integre array 
	public static void printArray(int[] inputArray, int sizeArray)
	{
		for (int i = 0; i < sizeArray; i++)
		{
			System.out.println(inputArray[i]);
		}
	}
	
	public static void main(String[] args) 
	{
		System.out.println("Sample ... ");
		
		// Sample array 
		int [] sampleArray = {1, 2, 3};
		printArray(sampleArray, 3);
		
		// Input values assumning a fixed length
		
		if(args.length == 3)
		{
			int[] inputArgsArray = new int[args.length];
			for (int i = 0; i < args.length; i++)
			{
				inputArgsArray[i] = Integer.parseInt(args[i]);
			}
			
			// Print the input arguments array 
			printArray(inputArgsArray, args.length); 
		}	
		
		// Print the public array 
		printPublicArray();	
	}
	
	
	
	
	
}

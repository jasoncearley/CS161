/**********************************************************************
 * Program: arrayAdd.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/05/14
 * Modified: 11/05/14
 * Description: This program will use a function to add two arrays 
 * 				element by element, storing each sum in the 
 * 				corresponding element of a third array. All array 
 * 				accesses is done with pointer arithmetic.
 * Output: Sum of user inputted arrays element by element.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // strings 
#include <cstdlib>   // atoi

using namespace std;

// Prototype Function(s)
void get_input(int*);
void array_math(int*, int*, int*, int); 

int main()
{
	// Initialize variable size to 0, this will hold user's array size
	int size = 0;
	int *size_ptr;
	
	// Establish pointers to respective parameters
	size_ptr = &size;
	
	cout << "How many values, upto 50, would you like to enter? ";
	get_input(size_ptr);
	
	cout << endl;
	
	// While loop to ensure user's array size is valid
	while (size > 50 || size < 0)
	{
		cout << "That value is outside the available range. Please try"
			 << " again. " << endl;
		get_input(size_ptr);
	}
	
	// Initialize array size based on user input
	int array1[size], array2[size], array3[size]; 
	
	// For loop to initialize array values to 0
	for (int a = 0; a < size; a++)
	{
		array1[a] = 0;
		array2[a] = 0;
		array3[a] = 0;
	}
	
	cout << "Starting with array 1....." << endl;
	
	// For loop to fill contents of array1 w/ user's input
	for (int a = 0; a < size; a++)
	{
		cout << "Enter value " << a + 1 << " of " << size << ": ";
		get_input(array1 + a);
	}
	
	cout << endl;
	cout << "Now for array 2....." << endl;
	
	// For loop to fill contents of array2 w/ user's input
	for (int a = 0; a < size; a++)
	{
		cout << "Enter value " << a + 1 << " of " << size << ": ";
		get_input(array2 + a);
	}
	
	cout << endl;
	cout << "Array1's values are: ";
	
	// For loop to display contents of Array1
	for (int a = 0; a < size; a++)
	{
		cout << " " << *(array1 + a) << " ";
	}
	
	cout << endl;
	cout << "Array2's values are: ";
	
	// For loop to display contents of Array2
	for (int a = 0; a < size; a++)
	{
		cout << " " << *(array2 + a) << " ";
	}
	
	array_math(array1 , array2 , array3, size);
	
	cout << endl;
	cout << "Array1 + Array2 = ";
	
	// For loop to display contents of Array3
	for (int a = 0; a < size; a++)
	{
		cout << " " << *(array3 + a) << " ";
	}
	
	cout << endl;
	
	return 0;
}

/***********************************************************************
 * This function gets the user's input value and validates it.
 **********************************************************************/
void get_input(int *num)
 {
	 string value = "";   // Variable to hold user's input
	 unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only numbers are entered
	do 
	{
		getline (cin, value);
		
		found1 = value.find_first_not_of ("1234567890-", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. Please try again. ";
		}  
	}
	while (found1 != 4294967295 || value.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	*num = (atoi (value.c_str()));
}

/***********************************************************************
 * This function adds the contents of Array1 and Array2 cell by cell
 * and stores the result in Array3.
 **********************************************************************/
void array_math(int *array1 , int *array2 , int *array3, int size)
{
	for (int a = 0; a < size; a++)
	{
		*(array3 + a) = *(array1 + a) + *(array2 + a);
	}
}

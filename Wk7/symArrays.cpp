/**********************************************************************
 * Program: symArrays.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/14/14
 * Modified: 11/14/14
 * Description: This program allows the user to use command line 
 * 				arguments to specify the sizes of 3 1D int arrays. It 
 * 				will then dynamically allocate the arrays using new. 
 * 				The user will enter the integers for each element in 
 * 				each array on a single line with whitespace separated 
 * 				values. The program will print out whether each array 
 * 				is symmetric or not.
 * Output: Whether each array is symmetric.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <limits> 	 // limits
#include <string>    // strings 
#include <cstdlib>   // atoi
#include <iomanip>	 // setw

using namespace std;

// Prototype Function(s)
int *create_array(int);
void fill_array(int*, int);
bool check_array(int*, int);

int main(int argc, char *argv[])
{
	// End program if user did not supply correct # of arguments
	if (argv[4])
	{
		cout << "You didn't enter the correct number of arguments." 
			 << endl;
		
		return 0;
	}
	
	int array1_size = 0, *array1,	// Est array 1 size and ptr
		array2_size = 0, *array2,	// Est array 2 size and ptr
		array3_size = 0, *array3;	// Est array 3 size and ptr
	
	array1_size = atoi(argv[1]);	// Convert argument 1 to an int
	array2_size = atoi(argv[2]);	// Convert argument 2 to an int
	array3_size = atoi(argv[3]);	// Convert argument 3 to an int
	
	// Call func to make array of correct size and return its addy
	array1 = create_array(array1_size); 
	array2 = create_array(array2_size);
	array3 = create_array(array3_size);
	
	// Call func to get user's input for each array
	fill_array (array1, array1_size);
	fill_array (array2, array2_size);
	fill_array (array3, array3_size);
	
	cout << endl;
	
	cout << "Array 1 is ";
	
	if (check_array(array1, array1_size))
	{
		cout << "Symmetric." << endl;
	}
	else
	{
		cout << "Not Symmetric." << endl;
	}
	
	delete [] array1;
	array1 = 0;
	
	cout << "Array 2 is ";
	
	if (check_array(array2, array2_size))
	{
		cout << "Symmetric." << endl;
	}
	else
	{
		cout << "Not Symmetric." << endl;
	}
	
	delete [] array2;
	
	cout << "Array 3 is ";
	
	if (check_array(array3, array3_size))
	{
		cout << "Symmetric." << endl;
	}
	else
	{
		cout << "Not Symmetric." << endl;
	}
	
	delete [] array3;
	
	return 0;
}

/***********************************************************************
 * This function will create a dynamic 1D array on the heap and returns
 * its address for use.
 **********************************************************************/
int *create_array(int size)
{	
	return new int[size];
}

/***********************************************************************
 * This function will fill the array with the user's input and validate
 * it.
 **********************************************************************/
void fill_array (int array[], int size)
{
	static int count = 1;
	
	bad:
	cout << "Please enter your numbers for array " << count
		 << " with a space separating each value." << endl;
	
	// For loop to fill 1D array
	for (int col = 0; col < size; col++)
	{
		cin >> array[col];
		
		// Ensure user didn't supply wrong data type	
		if (!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "That was not a valid entry. Please try again. ";
			goto bad;
		}
	}
	
	// Ensure user did not supply too many #'s for their array
	if (cin.peek() != 10)
	{
		cout << "You entered too many numbers for this array. " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto bad;
	}
	
	// Increment count to display array #
	count++;
}

/***********************************************************************
 * This function checks the dynamic array to see if it is symmetric.
 **********************************************************************/
bool check_array(int array[], int size)
{
	// Check for symmetry in an odd # array
	if (size % 2 != 0)
	{
		for (int a = 0, b = (size - 1); a != b; a++, b--)
		{
			if (array[a] != array[b])
			{
				return false;
			}
		}
	}
	
	// Check for symmetry in an even # array
	else
	{
		for (int a = 0, b = (size - 1); a < (size / 2); a++, b--)
		{
			if (array[a] != array[b])
			{
				return false;
			}
		}
	}
	
	return true;
}

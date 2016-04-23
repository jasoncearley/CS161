/**********************************************************************
 * Program: sameSum.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/12/14
 * Modified: 11/12/14
 * Description: This program will use a function that takes as 
 * 				parameters a square 2D array of ints and the number of 
 * 				rows in the user's square. The function returns a 
 * 				boolean value indicating whether all of the rows, 
 * 				columns, and both major diagonals of the user's square 
 * 				sum to the same value. In main, the user is asked for 
 * 				the size of their square.
 * Output: Whether all of the rows, columns, and both major diagonals 
 * 		   of the user's square sum to the same value.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <limits> 	 // limits
#include <string>    // strings 
#include <cstdlib>   // atoi
#include <iomanip>	 // setw

using namespace std;

// Prototype Function(s)
void get_input(int*);
int **create_array(int*);
bool array_check(int *array[], int); 

int main()
{
	// Initialize variable size to 0, this will hold user's array size
	int size = 0;
	int *size_ptr, **darr;
	
	// Establish pointers to respective parameters
	size_ptr = &size;
	
	cout << "How many rows/columns will your square 2D array contain? "
		 << "You can have up to a max of 10. ";
	get_input(size_ptr);
	
	// Ensure size of array is correct
	if (size > 10 || size < 2) 
	{
		cout << "That is not a valid sized square array. Please choose "
			 << "a number between 2 and 10. ";
		get_input(size_ptr);
	}
	
	// Create dynamic array of size n by n; where n = size
	darr = create_array(size_ptr);
				 
	for (int row = 0; row < size; row++)
	{
		bad:
		cout << "Please enter your numbers for row " << row + 1
			 << " with a space separating each value. ";
		
		for (int col = 0; col < size; col++)
		{
			cin >> darr[row][col];
			
			if (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "That was not a valid entry. Please try again. ";
				goto bad;
			}
		}
	}
	
	if (array_check(darr, size))
	{
		cout << "All of the rows, columns, and both major diagonals" 
			 << " of your square array sum to the same value." << endl;
	}
	
	else
	{
		cout << "Sorry, all of the rows, columns, and both major " 
			 << "diagonals of your square array do not sum to the same " 
			 << "value." << endl;
	}
	
	// Deallocate darr memory
	for (int a = 0; a < size; a++)
	{
		delete [] darr[a];
		darr[a] = 0;
	}
	
	delete [] darr;
	darr = 0;
	
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
		
		found1 = value.find_first_not_of ("1234567890", 0);
		
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
 * This function will create a dynamic 2D array on the heap and return
 * its address for use.
 **********************************************************************/
int **create_array(int *size)
{
	int **temp;
	
	// Create new dynamic array row pointers
	temp = new int*[*size];
	
	// Assign row pointers to new dynamic array rows of n columns
	for (int a = 0; a < *size; a++)
	{
		temp[a] = new int[*size];
	}
	
	return temp;
}

/***********************************************************************
 * This function checks the dynamic array to see if all of the rows, 
 * columns, and both major diagonals sum to the same value.
 **********************************************************************/
bool array_check(int *array[], int size)
{
	int total = 0;
	int temp_array[size];
	
	// Look at rows first
	for (int row = 0; row < size; row++)
	{
		// Reset accumulator to 0 for this row
		total = 0;
		
		// Sum all the cols in this row
		for (int col = 0; col < size; col++)
		{
			total += array[row][col];
		}
		
		// Store sum of this row in an array for comparision
		temp_array[row] = total;
	}
	
	// Check to see if the sum of each row is equal
	for (int a = 0; a < (size - 1); a++)
	{
		if (temp_array[a] != temp_array[a + 1])
		{
			return false;
		}
	}
	
	// Look at columns next
	for (int col = 0; col < size; col++)
	{
		// Reset accumulator to 0 for this col
		total = 0;
		
		// Sum all the rows in this col
		for (int row = 0; row < size; row++)
		{
			total += array[row][col];
		}
		
		// Store sum of this col in an array for comparision
		temp_array[col] = total;
	}
	
	// Check to see if the sum of each col is equal
	for (int a = 0; a < (size - 1); a++)
	{
		if (temp_array[a] != temp_array[a + 1])
		{
			return false;
		}
	}
	
	// Reset accumulator to 0 
	total = 0;
	
	// Look at one major diagonal next
	for (int a = 0; a < size; a++)
	{
		total += array[a][a];
	}
	
	// Store sum in an array for comparision
	temp_array[0] = total;
	
	// Reset accumulator to 0 
	total = 0;
	
	// Look at next major diagonal
	for (int a = (size - 1), b = 0; a >= 0; a--, b++)
	{
		total += array[a][b];
	}
	
	// Store sum in an array for comparision
	temp_array[1] = total;
	
	// Check to see if the sum of each major diagonal is equal
	if (temp_array[0] != temp_array[1])
	{
		return false;
	}
	
	return true;
}

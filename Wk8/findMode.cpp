/**********************************************************************
 * Program: findMode.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/20/14
 * Modified: 11/20/14
 * Description: This program allows the user to input any number of 
 * 				integers and stores them in a vector. It will then call
 * 				a function to find the Mode(s) of the data and return
 * 				that as another vector.  
 * Output: Values in the Mode(s) vector.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // strings 
#include <cstdlib>   // atoi
#include <vector>	 // vectors
#include <algorithm> // sort

using namespace std;

// Define Structures
struct Data
{
	int value;
	int frequency;
	
	// Constructor
	Data(int a = 0)
	{
		value = a;
		frequency = a;
	}
	
	// Found this example on cplusplus.com to allow sorting of structs
	bool operator() (Data i, Data j) {return (i.frequency>j.frequency);}
} frequency;

// Prototype Function(s)
void get_input(int*, string*);
vector <Data> find_modes (vector <int>);

int main()
{
	vector <int> numbers;	// Vector to hold user's values
	int temp_num = 0, 		// Allow adding user input to vector
 		*temp_num_ptr;		// Used for function get_input
	string stop = "No", 	// To quit Do/while loop when needed
		   *stop_ptr;		// Used for function get_input
	
	// Set pointers to appropriate addresses
	temp_num_ptr = &temp_num;
	stop_ptr = &stop;
	
	cout << "Enter your integers one at a time. When you are done"
		 << " enter \"-i\" to stop." << endl;
	
	// Do/while loop to allow user to enter values until "-i" is entered
	do
	{		 
		// Call to function to get/validate user input
		get_input(temp_num_ptr, stop_ptr);
		
		// Store valid input in vector
		numbers.push_back(temp_num);
	}
	while (stop != "Yes");
	
	// Remove -i at end of vector
	numbers.pop_back(); 
	
	// Sort the user's inputted values
	sort(numbers.begin(), numbers.end());
	
	cout << endl
		 << "Here are your values in order from lowest to highest."
		 << endl;
	
	for (unsigned a = 0; a < numbers.size(); a++)
	{
		cout << numbers[a] << " ";
	}
	
	cout << endl << endl;
	
	// Create a vector of Data structs to hold value and frequency
	vector <Data> mode;
	
	// Call to function used to find the modes of the inputted values
	mode = find_modes(numbers);
	
	cout << "Your modes(s) is(are) as follows:" << endl;
	
	for (unsigned a = 0; a < mode.size(); a++)
	{			
		if (mode[a].frequency >= mode[0].frequency)
		{
			cout << "Value: " << mode[a].value << " Frequency: " 
				 << mode[a].frequency << endl;
		}
	}
	
	cout << endl;
	
	return 0;
}

/***********************************************************************
 * This function gets the user's input, validates it, and returns
 * it.
***********************************************************************/
void get_input(int *num, string *quit)
{
	string number = "";  // Variable to hold user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only contains valid numbers
	do 
	{
		getline (cin, number);
	
		if (number == "-i")
		{
			*quit = "Yes";
			break;
		}
		
		found1 = number.find_first_not_of ("1234567890-", 0);
		
		if (found1 != 4294967295 || number.size() > 20)
		{
			cout << "That is not a valid entry. Please try again: "
				 << endl;
		}
	}
	while (found1 != 4294967295 || number.size() > 20);
	
	// atoi converts string into an integer
	*num = atoi (number.c_str());	
}

/***********************************************************************
 * This function takes the user's input in the form of a vector and 
 * finds the mode(s). It returns a vector of structs, which contains 
 * each number with the frequency of appearances.
***********************************************************************/
vector <Data> find_modes(vector <int> numbers)
{	
	// Initialize variables to appropriate values
	int count = 1,
		index = 0;
	
	// Count the number of different values
	for (unsigned a = 0; a < (numbers.size() - 1); a++)
	{
		if (numbers[a] != numbers[a + 1])
		{
			count++;
		}
	}
	
	// Create a local version to store info until it can be returned
	vector <Data> mode(count);
	
	// Store 1st value in numbers vector to mode structure vector
	mode[index].value = numbers[0];
	mode[index].frequency = 1;
	
	// Inspect each value in numbers vector
	for (unsigned a = 0; a < (numbers.size() - 1); a++)
	{	
		// If different, store value in next open spot of mode vect & 
		// set frequency to 1 
		if (numbers[a] != numbers[a + 1])
		{
			index++;
			mode[index].value = numbers[a + 1];
			mode[index].frequency = 1;
		}
		
		// If same, increment frequency by 1
		else
		{
			mode[index].frequency++;
		}
	}
	
	// Sort mode vector based on frequency from high to low
	sort(mode.begin(), mode.end(), frequency);
	
	// Return sorted mode vector to main	
	return mode;
}

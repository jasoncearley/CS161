/**********************************************************************
 * Program: grades.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/04/14
 * Modified: 11/04/14
 * Description: This program is a text-based histogram for a quiz given 
 * 				to a class of students. The quiz is graded on a scale 
 * 				from 0 to 5. This program will allow you to enter grades 
 * 				for each student.
 * Output: Number of grades for each score (0-5)
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // Strings and atoi 

using namespace std;

// Prototype Function(s)
int get_values();
int array_math(const int [], int);

int main()
{
	int array[6] = {0,0,0,0,0,0},
		num_students = 0,
		count_students = 0,
		score = 0;
	
	cout << "Enter -1 when finished." << endl;;
	
	num_students = 0;
	
	do
	{
		cout << "Enter score for student " << count_students + 1 << ": ";
		
		again:
		score = get_values();
		
		if (score == 0)
		{
			array[0] += 1;
		}
		
		else if (score == 1)
		{
			array[1] += 1;
		}
		
		else if (score == 2)
		{
			array[2] += 1;
		}
		
		else if (score == 3)
		{
			array[3] += 1;
		}
		
		else if (score == 4)
		{
			array[4] += 1;
		}
		
		else if (score == 5)
		{
			array[5] += 1;
		}
		
		else if (score == -1)
		{
			num_students = -1;
		}
		
		else
		{
			cout << "That is not a valid score. Please try again. ";
			goto again;
		}
		
		count_students++;
	}
	while (num_students == 0);
	
	for (int a = 0; a < 6; a++)
	{
		cout << array[a] << " grade(s) of " << a << endl;
	}
	
	return 0;
}

/***********************************************************************
 * This function gets the user's values.
 **********************************************************************/
int get_values()
{
	 string number = ""; 		// Variable to hold user's input
	 unsigned found1 = 0; 	// Variable used to detect non-numeric entries
	 
	 // Do/while loop ensures low only contains numbers
	do 
	{
		getline (cin, number);
	
		found1 = number.find_first_not_of ("123450-", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. Please try again." 
				 << endl;
		}  
	}
	while (found1 != 4294967295 || number.size() > 2);
	
	// atoi converts string into an integer
	return atoi (number.c_str());
}

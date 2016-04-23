/**********************************************************************
 * Program: recFun.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/28/14
 * Modified: 10/28/14
 * Description: This program will ask the user for an interger (n) and 
 * 				then generate the nth Fibonacci number. 
 * Output: The nth Fibonacci number
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // Strings and atoi 

using namespace std;

// Prototype Function(s)
int get_num();
int fib(int number);

int main()
{
	int num = 0;
	
	num = get_num();
	
	cout << "The number is " << fib(num) << endl;
	
	return 0;
}

/***********************************************************************
 * This function gets the user's value for the nth Fibonacci number 
 * and validates it.
 **********************************************************************/
int get_num()
{
	string number = ""; 	 // String to store user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	
	// Do/while loop ensures high only contains numbers
	do
	{
		cout << "Which Fibonacci number would you like me to calculate? ";	 
		getline (cin, number);
		
		found1 = number.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. ";
		}  
	} 
	while (found1 != 4294967295 || number.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	return (atoi (number.c_str()));
}

/***********************************************************************
 * This function calculates tne nth Fibonacci number using recursion.
 * ********************************************************************/
int fib(int num)
{
	if (num == 0)
	{
		return 0;
	}
	
	if (num == 1)
	{
		return 1;
	}
	
	else if (num > 1)
	{
		return (fib(num-2) + fib(num-1));
	}
}

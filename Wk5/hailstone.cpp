/**********************************************************************
 * Program: hailstone.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/28/14
 * Modified: 10/28/14
 * Description: This program will ask the user for an interger (n) and 
 * 				then generate the hailstone sequence from that number. 
 * Output: The hailstone sequence for the given number
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // Strings and atoi 

using namespace std;

// Prototype Function(s)
int get_num();
int hailstone_seq(int number);

int main()
{
	int num = 0;
	
	num = get_num();

	hailstone_seq(num);
		 
	return 0;
}
	
/***********************************************************************
 * This function gets the user's value for the hailstone sequence 
 * and validates it.
 **********************************************************************/
int get_num()
{
	string number = ""; 	 // String to store user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	
	// Do/while loop ensures high only contains numbers
	do
	{
		cout << "Enter an integer and I will show you its hailstone "
			 << "sequence. ";	 
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
 * This function calculates the hailstone sequence for the given number
 * and the number of steps it takes to reach 1.
 **********************************************************************/
int hailstone_seq(int num)
{
	static int count = 0;
	
	if (num == 1)
	{
		cout << num << endl;
		cout << "It took " << count << " steps to reach 1" << endl;
		return 1;
	}
	
	if (num % 2 == 0)
	{
		cout << num << "  ";
		count++;
		return hailstone_seq(num / 2);
	}
	
	else
	{
		cout << num << "  ";
		count++;
		return hailstone_seq((num * 3) + 1);
	}
}

/**********************************************************************
 * Program: echo.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/4/14
 * Modified: 10/4/14
 * Description: This program will asks the user to input a whole number
 * 				and then display that number on the sceen.
 * Input: Whole number
 * Output: User entered whole number. 
 * *******************************************************************/

#include <iostream>
using namespace std;

int main()
{
	long number;
	
	cout << "Please enter a whole number: ";
	cin >> number;
	cout << "You entered " << number << endl;
	
	return 0;
	
}	

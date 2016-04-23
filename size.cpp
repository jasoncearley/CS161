/**********************************************************************
 * Program: size.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/4/14
 * Modified: 10/4/14
 * Description: This program will display the size of certain data 
 * 				types on any system.
 * Input: None
 * Output: Size of each data type on the applicable machine. 
 * *******************************************************************/

#include <iostream>
using namespace std;

int main()
{
	
	cout << "short integer " << sizeof(short) << endl
		 << "int " << sizeof(int) << endl
		 << "long integer " << sizeof(long) << endl
		 << "float " << sizeof(float) << endl
		 << "Double float " << sizeof(double) << endl
		 << "Long Double float " << sizeof(long double) << endl;
	
	return 0;
	
}

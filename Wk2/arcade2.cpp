/**********************************************************************
 * Program: arcade2.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/8/14
 * Modified: 10/8/14
 * Description: This program will will determine how many candy bars
 * 				and gum balls the user can get based on the number
 * 				of coupons they input using loops.
 * Input: # of coupons
 * Output: # of candy bars and gum balls 
 * *******************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int coupons;					// Establish variable to hold number of users coupons
	int candy_bar_counter = 0;		// Initialize counter for candy bars to 0
	int gum_ball_counter = 0;		// Initialize counter for gum balls to 0
	
	cout << "Please enter the number of coupons you have: ";
	cin >> coupons;
	
	// Determines number of candy bars user can get w/o using division
	while (coupons >= 10)
	{
		coupons = coupons - 10;
		candy_bar_counter++;
	}
	
	// If/else statement for correct grammer
	if (candy_bar_counter == 1)
	{
		cout << "You can get " << candy_bar_counter << " candy bar"
			 << " and ";
	}
	
	else
	{
		cout << "You can get " << candy_bar_counter << " candy bars"
			 << " and ";
	}	
	
	// Determines number of gum balls user can get w/o using division
	while (coupons < 10 && coupons >= 3)
	{
		coupons = coupons - 3;
		gum_ball_counter++;
	}
	
	// If/else statement for correct grammer
	if (gum_ball_counter == 1)
	{
		cout << gum_ball_counter << " gum ball." << endl;
	}
	
	else
	{
		cout << gum_ball_counter << " gum balls." << endl;
	}
	
	// Tells user number of remaining coupons
	if (coupons == 2)
	{
		cout << "You now have " << coupons << " coupons"
			 << " remaining." << endl;
	}
	
	// Tells user number of remaining coupons
	if (coupons == 1)
	{
		
		cout << "You now have " << coupons << " coupon"
			 << " remaining." << endl;
	}
	
	return 0;
}

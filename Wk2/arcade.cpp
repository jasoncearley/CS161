/**********************************************************************
 * Program: arcade.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/8/14
 * Modified: 10/8/14
 * Description: This program will will determine how many candy bars
 * 				and gum balls the user can get based on the number
 * 				of coupons they input.
 * Input: # of coupons
 * Output: # of candy bars and gum balls 
 * *******************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int coupons, 		// Establish variable to hold number of users coupons
		candy_bars, 	// Establish variable to hold number of candy bars
		gum_balls;		// Establish variable to hold number of gum balls
	
	cout << "Please enter the number of coupons you have: ";
	cin >> coupons;
	
	candy_bars = coupons / 10; // calculate how many candy bars user can get
	
	// If/else statement to use correct grammer
	if (candy_bars == 1)
	{
		cout << "You can get " << candy_bars << " candy bar and ";
	}
	
	else
	{
		cout << "You can get " << candy_bars << " candy bars and ";
	}
		
	gum_balls = (coupons % 10)/3; // calculates how many gum balls user can get
	
	// If/else statement to use correct grammer	
	if (gum_balls == 1)
	{
		cout << gum_balls << " gum ball." << endl;
	}
	
	else
	{
		cout << gum_balls << " gum balls." << endl;
	}
	return 0;
}

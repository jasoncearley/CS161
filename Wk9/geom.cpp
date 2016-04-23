/**********************************************************************
 * Program: geom.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/26/14
 * Modified: 11/26/14
 * Description: This program will calculate the slope and length of a 
 * 				line given its endpoints in (x, y) coordinates.
 * Output: Slope and length of a line.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cmath>	 // sqrt and pow functions
#include <string>

using namespace std;

// Define Classes
class Point
{
	private:
	double xCoord, yCoord;
	
	public:
	Point() { xCoord = yCoord = 0.0; }
	void set_coordinates(double x, double y);
	double get_xCoord() const {return xCoord;}
	double get_yCoord() const {return yCoord;}
	double distanceTo(const Point &);
};

class LineSegment
{
	private:
	Point first, second;
	
	public:
	void set_LineSegment(Point &a, Point &b)
	{
		first = a;
		second = b;
	}
	
	double length()
	{
		return first.distanceTo(second);
	}
	
	double slope()
	{		
		return ((second.get_yCoord() - first.get_yCoord()) / 
				(second.get_xCoord() - first.get_xCoord()));
	}	
		
};	 
	
// Class Functions
void Point::set_coordinates(double x, double y)
{
	xCoord = x;
	yCoord = y;
}

/***********************************************************************
 * This function calculates the distance b/w two points.
 * ********************************************************************/
double Point::distanceTo(const Point &p)
{
	double a, b, c;
	
	a = pow((get_xCoord() - p.xCoord), 2.0);
	b = pow((get_yCoord() - p.yCoord), 2.0);
	c = sqrt(a + b);
	
	return c; 
}


int main()
{
	double x1, y1, x2, y2;	// Variables to hold data for points
	string again = "";		// Variable to allow user to go agian
	Point p1, p2;			// Point class objects
	
	do
	{
		cout << "Point 1, x value: ";
		cin >> x1;
	
		cout << "Point 1, y value: ";
		cin >> y1;
	
		cout << "Point 2, x value: ";
		cin >> x2;
	
		cout << "Point 2, y value: ";
		cin >> y2;
	
		p1.set_coordinates(x1, y1);
		p2.set_coordinates(x2, y2);
		
		// LineSegment object
		LineSegment line;
		line.set_LineSegment(p1, p2);
	
		cout << "The length of your line is " << line.length() << endl;
		
		// Check if line is verticle or not
		if (isinf(line.slope()))
		{
			cout << "Your line is verticle." << endl;
		}
	
		else
		{
			cout << "The slope of your line is " << line.slope() << endl;
		}
	
		cin.ignore();
		cout << "Go again? [y/n] ";
		getline(cin, again);
	
		cout << endl;
	}
	while(again == "y");
	
	return 0;
}

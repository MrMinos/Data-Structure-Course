// Lab 1a, Class Programming And Testing
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include <iostream> 
using namespace std;

#include <cassert>

#include "Road.h"
#include "Road.h" // Testing ifndef

int main() 
{ 
  // print my name and this assignment's title 
  cout << "Lab 1a, Class Programming And Testing"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  Road road;
  double thickness=0;

  road.SetWidth(100);
  road.SetLength(1);
  thickness = 0.25;
  cout << "Width in feet " << road.GetWidth() << "\n";
  cout << "Length in miles " << road.GetLength() << "\n";
  cout << "Thickness in inches 0.25\n";
  cout << "Expected asphalt volume in cubic feet: 11000\n";
  cout << "Result of function asphalt: " << road.asphalt(0.25) << "\n";
  assert(11000 == road.asphalt(thickness));
  cout << "\n";

  road.SetWidth(60);
  road.SetLength(3.3);
  thickness = 1;
  cout << "Width in feet " << road.GetWidth() << "\n";
  cout << "Length in miles " << road.GetLength() << "\n";
  cout << "Thickness in inches 1\n";
  cout << "Expected asphalt volume in cubic feet: 87120\n";
  cout << "Result of function asphalt: " << road.asphalt(1) << "\n";
  assert(87120 == road.asphalt(thickness));
  cout << "\n";

  road.SetWidth(120.54);
  road.SetLength(25);
  thickness = 1.5;
  cout << "Width in feet " << road.GetWidth() << "\n";
  cout << "Length in miles " << road.GetLength() << "\n";
  cout << "Thickness in inches 1.5\n";
  cout << "Expected asphalt volume in cubic feet: 1988910\n";
  cout << "Result of function asphalt: " << road.asphalt(1.5) << "\n";
  assert(1988910 == road.asphalt(thickness));
  cout << "\n";


  road.SetWidth(97.34);
  road.SetLength(203.45);
  thickness = 1.2;
  cout << "Width in feet " << road.GetWidth() << "\n";
  cout << "Length in miles " << road.GetLength() << "\n";
  cout << "Thickness in inches 1.2\n";
  cout << "Expected asphalt volume in cubic feet: 10456418.544\n";
  cout << "Result of function asphalt: " << road.asphalt(1.2) << "\n"; 
  assert(10456418.544 == road.asphalt(thickness));
  cout << "\n";

  Road copy = road;

  cout << "Width of road: " << road.GetWidth() << "\n";
  cout << "Width of copy: " << copy.GetWidth() << "\n";
  assert(copy.GetWidth() == road.GetWidth());
  cout << "Length of road: " << road.GetLength() << "\n";
  cout << "Length of copy: " << copy.GetLength() << "\n\n";
  assert(copy.GetLength() == road.GetLength());

  Road copy2; copy2 = road;

  cout << "Width of road: " << road.GetWidth() << "\n";
  cout << "Width of copy2: " << copy2.GetWidth() << "\n";
  assert(copy2.GetWidth() == road.GetWidth());
  cout << "Length of road: " << road.GetLength() << "\n";
  cout << "Length of copy2: " << copy2.GetLength() << "\n\n";
  assert(copy2.GetLength() == road.GetLength());

}
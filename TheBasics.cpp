// Lab 0c, Console Programming Basics
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() 
{ 
  int age = 0;
  double tempe = 0.0;
  double ctempe = 0.0;
  string name;
  string city;
  char buf[100];

  // print my name and this assignment's title 
  cout << "Lab 0c, Console Programming Basics"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  cout << "Enter your age: ";
  cin >> buf; age = atoi(buf);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter your name: ";
  getline(cin, name);

  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf; tempe = atof(buf);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "What city are you in right now? ";
  getline(cin, city);

  ctempe = tempe;
  ctempe = ( ctempe - 32 ) * 5 / 9;
  ctempe = floor( ctempe * 10 + 0.5) / 10;

  cout << endl << name << " is " << age << " years old now, and will be " << age+1 << " a year from now." << endl;
  cout << "It's ";
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << tempe << " degrees F in " << city << " -- that's ";
  cout.setf(ios::fixed|ios::showpoint); 
  cout << setprecision(1);
  cout << ctempe << " degrees C." << endl;

}
// Lab 3b, const And Constructors, Part 2
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include <iostream> 
using namespace std;

#include <cassert>

#include "Time.h"
#include "Time.h" // Testing ifndef

int main() 
{ 
  // print my name and this assignment's title 
  cout << "Lab 3b, const And Constructors, Part 2"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  int hour, minute, second;
  Time test = Time();

  hour = 1; test.setHours(hour);
  minute = 40; test.setMinutes(minute);
  second = 30; test.setSeconds(second);
  cout << "Hours: " << hour << "\n";
  cout << "Minutes: " << minute << "\n";
  cout << "Seconds: " << second << "\n";
  cout << "Expected Time in Hours: 1.675\n";
  cout << "Calculated Time in Hours: " << test.timeInHours() << "\n";
  assert(1.675==test.timeInHours());
  cout << "Expected Time in Minutes: 100.5\n";
  cout << "Calculated Time in Minutes: " << test.timeInMinutes() << "\n";
  assert(100.5==test.timeInMinutes());
  cout << "Expected Time in Seconds: 6030\n";
  cout << "Calculated Time in Seconds: " << test.timeInSeconds() << "\n\n";
  assert(6030==test.timeInSeconds());

  hour = 2; test.setHours(hour);
  minute = 30; test.setMinutes(minute);
  second = 0; test.setSeconds(second);
  cout << "Hours: " << hour << "\n";
  cout << "Minutes: " << minute << "\n";
  cout << "Seconds: " << second << "\n";
  cout << "Expected Time in Hours: 2.5\n";
  cout << "Calculated Time in Hours: " << test.timeInHours() << "\n";
  assert(2.5==test.timeInHours());
  cout << "Expected Time in Minutes: 150\n";
  cout << "Calculated Time in Minutes: " << test.timeInMinutes() << "\n";
  assert(150==test.timeInMinutes());
  cout << "Expected Time in Seconds: 9000\n";
  cout << "Calculated Time in Seconds: " << test.timeInSeconds() << "\n\n";
  assert(9000==test.timeInSeconds());

  hour = 0; test.setHours(hour);
  minute = 30; test.setMinutes(minute);
  second = 0; test.setSeconds(second);
  cout << "Hours: " << hour << "\n";
  cout << "Minutes: " << minute << "\n";
  cout << "Seconds: " << second << "\n";
  cout << "Expected Time in Hours: 0.5\n";
  cout << "Calculated Time in Hours: " << test.timeInHours() << "\n";
  assert(0.5==test.timeInHours());
  cout << "Expected Time in Minutes: 30\n";
  cout << "Calculated Time in Minutes: " << test.timeInMinutes() << "\n";
  assert(30==test.timeInMinutes());
  cout << "Expected Time in Seconds: 1800\n";
  cout << "Calculated Time in Seconds: " << test.timeInSeconds() << "\n\n";
  assert(1800==test.timeInSeconds());

  test = Time(0, 12, 0);
  cout << "Hours: " << hour << "\n";
  cout << "Minutes: " << minute << "\n";
  cout << "Seconds: " << second << "\n";
  cout << "Expected Time in Hours: 0.2\n";
  cout << "Calculated Time in Hours: " << test.timeInHours() << "\n";
  assert(0.2==test.timeInHours());
  cout << "Expected Time in Minutes: 12\n";
  cout << "Calculated Time in Minutes: " << test.timeInMinutes() << "\n";
  assert(12==test.timeInMinutes());
  cout << "Expected Time in Seconds: 720\n";
  cout << "Calculated Time in Seconds: " << test.timeInSeconds() << "\n\n";
  assert(720==test.timeInSeconds());

  test = Time(0, 30, 0);
  cout << "Hours: " << hour << "\n";
  cout << "Minutes: " << minute << "\n";
  cout << "Seconds: " << second << "\n";
  cout << "Expected Time in Hours: 0.5\n";
  cout << "Calculated Time in Hours: " << test.timeInHours() << "\n";
  assert(0.5==test.timeInHours());
  cout << "Expected Time in Minutes: 30\n";
  cout << "Calculated Time in Minutes: " << test.timeInMinutes() << "\n";
  assert(30==test.timeInMinutes());
  cout << "Expected Time in Seconds: 1800\n";
  cout << "Calculated Time in Seconds: " << test.timeInSeconds() << "\n\n";
  assert(1800==test.timeInSeconds());

  const Time copy = test;
  cout << "Calculated Time in Hours @ copy: " << copy.timeInHours() << "\n";
  cout << "Calculated Time in Hours @ test: " << test.timeInHours() << "\n";
  assert(copy.timeInHours()==test.timeInHours());
  cout << "Calculated Time in Minutes @ copy: " << copy.timeInMinutes() << "\n";
  cout << "Calculated Time in Minutes @ test: " << test.timeInMinutes() << "\n";
  assert(copy.timeInMinutes()==test.timeInMinutes());
  cout << "Calculated Time in Seconds @ copy: " << copy.timeInSeconds() << "\n";
  cout << "Calculated Time in Seconds @ test: " << test.timeInSeconds() << "\n\n";
  assert(copy.timeInSeconds()==test.timeInSeconds());

  Time copy2 = Time(0,0,0); copy2 = test;
  cout << "Calculated Time in Hours @ copy2: " << copy2.timeInHours() << "\n";
  cout << "Calculated Time in Hours @ test: " << test.timeInHours() << "\n";
  assert(copy2.timeInHours()==test.timeInHours());
  cout << "Calculated Time in Minutes @ copy2: " << copy2.timeInMinutes() << "\n";
  cout << "Calculated Time in Minutes @ test: " << test.timeInMinutes() << "\n";
  assert(copy2.timeInMinutes()==test.timeInMinutes());
  cout << "Calculated Time in Seconds @ copy2: " << copy2.timeInSeconds() << "\n";
  cout << "Calculated Time in Seconds @ test: " << test.timeInSeconds() << "\n\n";
  assert(copy2.timeInSeconds()==test.timeInSeconds());
}
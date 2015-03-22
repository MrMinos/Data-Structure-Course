// Lab 8a, Write And Apply A Stack Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include <cassert>

#include <iostream>
using namespace std;

#include "Stack.h"
#include "Stack.h" //ifndef test

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 8a, Write And Apply A Stack Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  Stack<int> stack;

  stack.push(66);
  stack.push(3);
  cout << "Expected stack size: 2, Real size: " << stack.size() << endl;
  assert(stack.size() == 2);

  stack.pop();
  cout << "Expected stack size: 1, Real size: " << stack.size() << endl;
  assert(stack.size() == 1);
  cout << "Expected top stack value: 66, Real value: " << stack.peek() << endl;
  assert(stack.peek() == 66);
  stack.pop();

  cout << "Stack expected to be empty, Real value: " << stack.empty() << endl;
  assert(stack.empty());

  stack.push(5666);
  stack.push(634);
  stack.push(0);
  stack.push(3);
  cout << "Stack size expected to be 4, Real value: " << stack.size() << endl;
  assert(stack.size() == 4);

  Stack<int> test = stack;
  assert(test.peek() == 66);
  assert(test.size() == 1);

  Stack<int> test2; test2 = stack;
  assert(test.peek() == 66);
  assert(test.size() == 1);
 
}
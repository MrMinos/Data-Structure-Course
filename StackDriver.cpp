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

  cout << "Stack expected to be empty, Real value(1 = empty): " << stack.empty() << endl;
  assert(stack.empty());

  stack.push(5666);
  stack.push(634);
  stack.push(0);
  stack.push(3);
  cout << "Stack size expected to be 4, Real value: " << stack.size() << endl;
  assert(stack.size() == 4);

  Stack<int> test = stack;
  cout << "Expected test peek 3, Real value: " << test.peek() << endl;
  assert(test.peek() == 3);
  cout << "Expected test size 4, Real Value: " << test.size() << endl;
  assert(test.size() == 4);

  Stack<int> test2; test2 = stack;
  cout << "Expected test2 peek 3, Real value: " << test2.peek() << endl;
  assert(test2.peek() == 3);
  cout << "Expected test size 4, Real Value: " << test2.size() << endl;
  assert(test2.size() == 4);
 
  stack.pop();
  stack.pop();
  stack.pop();
  cout << "Expected stack peek value 5666, Real value: " << stack.peek() << endl;
  assert(stack.peek() == 5666);
  stack.pop();
  cout << "Expected stack size value 0, Real value: " << stack.size() << endl;
  stack.pop();
  assert(stack.size() == 0);
  cout << "Expected stack size value 0, Real value: " << stack.size() << endl;
  test.push(6666);
  test2.push(7777);
  cout << "Expected test peek value: 6666, Real value: " << test.peek() << endl;
  cout << "Expected test2 peek value: 7777, Real value: " << test2.peek() << endl;
  test.pop();
  cout << "Expected test peek value: 3, Real value: " << test.peek() << endl;

  stack.clear();
  test.clear();
  test2.clear();

  cout << "Expected stack size value: 0, Real value: " << stack.size() << endl;
  assert(stack.size() == 0);
  cout << "Expected test size value: 0, Real value: " << test.size() << endl;
  assert(test.size() == 0);
  cout << "Expected test2 size value: 0, Real value: " << test2.size() << endl;
  assert(test2.size() == 0);

  stack.pop();
  test.pop();
  test2.pop();

  cout << "Expected stack size value: 0, Real value: " << stack.size() << endl;
  assert(stack.size() == 0);
  cout << "Expected test size value: 0, Real value: " << test.size() << endl;
  assert(test.size() == 0);
  cout << "Expected test2 size value: 0, Real value: " << test2.size() << endl;
  assert(test2.size() == 0);

  test.push(5555);
  test.push(9999);
  stack.push(3333);
  test2.push(9999);
  test2.push(5555);

  cout << "Run various assertions and tests" << endl;
  assert(test.size() == 2);
  assert(test2.size() == 2);
  assert(stack.size() == 1);
  test2.pop();
  assert(test.peek() == test2.peek());
  assert(test.peek() == 9999);
  assert(test2.size() == 1);
  cout << "Test passed" << endl;
  

}
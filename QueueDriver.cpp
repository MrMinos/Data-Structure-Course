// Lab 8b, Write And Test A Queue Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include <cassert>

#include <iostream>
using namespace std;

#include "Queue.h"
#include "Queue.h" //ifndef test

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 8b, Write And Test A Queue Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  Queue<int> queue;

  queue.push(66);
  queue.push(3);
  cout << "Expected queue size: 2, Real size: " << queue.size() << endl;
  assert(queue.size() == 2);

  queue.pop();
  cout << "Expected queue size: 1, Real size: " << queue.size() << endl;
  assert(queue.size() == 1);
  cout << "Expected top queue value: 3, Real value: " << queue.peek() << endl;
  assert(queue.peek() == 3);
  queue.pop();

  cout << "Queue expected to be empty, Real value: " << queue.empty() << endl;
  assert(queue.empty());

  queue.push(5666);
  queue.push(634);
  queue.push(0);
  queue.push(3);
  cout << "Queue size expected to be 4, Real value: " << queue.size() << endl;
  assert(queue.size() == 4);

  Stack<int> test = stack;
  assert(test.peek() == 66);
  assert(test.size() == 1);

  Stack<int> test2; test2 = stack;
  assert(test.peek() == 66);
  assert(test.size() == 1);
 
}
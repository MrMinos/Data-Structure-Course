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

  Queue<int> test = queue;
  cout << "Expected test peek 5666, Real value: " << test.peek() << endl;
  assert(test.peek() == 5666);
  cout << "Expected test size 4, Real Value: " << test.size() << endl;
  assert(test.size() == 4);

  Queue<int> test2; test2 = queue;
  cout << "Expected test2 peek 5666, Real value: " << test2.peek() << endl;
  assert(test2.peek() == 5666);
  cout << "Expected test size 4, Real Value: " << test2.size() << endl;
  assert(test2.size() == 4);
 
  queue.pop();
  queue.pop();
  test.pop();
  test2.pop();
  test.pop();
  cout << "Test popped twice and Queue popped twice their peek should match" << endl;
  assert(test.peek() == queue.peek());
  cout << "Matched" << endl;
  test.pop();
  test.pop();
  cout << "Test should be empty, Real value (Empty = 1): " << test.empty() << endl;
  assert(test.empty() == 1);
  test2.pop();
  test.push(0);
  cout << "Test and test2 should match due to few pops and push" << endl;
  assert(test.peek() == test2.peek());

  queue.clear();
  cout << "Queue should be empty, Real value (Empty = 1): " << queue.empty() << endl;
  assert(1 == queue.empty());
  queue.push(1111);
  queue.push(5632);
  cout << "Queue size should be 2, Real Value: " << queue.size() << endl;
  assert(2 == queue.size());
  test.clear();
  test.push(1111);
  cout << "test peek and queue peek should match queue peek: " << queue.peek() << "test peek: " << test.peek() << endl;
  assert (test.peek() == queue.peek());
  cout << "Matched" << endl;
}
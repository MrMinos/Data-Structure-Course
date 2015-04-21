// Lab 12a, Write And Test A Priority Queue Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include "PriorityQueue.h"
#include "PriorityQueue.h" // testing ifndef

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 12a, Write And Test A Priority Queue Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  int tempInt;
  
  PriorityQueue<int> l;
  
  cout << "Expected empty: 1 (TRUE)" << endl;
  cout << "Actual empty: " << l.empty() << endl << endl;
  assert(l.empty() == 1);
  
  cout << "Expected size: 0" << endl;
  cout << "Actual size: " << l.size() << endl << endl;
  assert(l.size() == 0);
  
  
  cout << "Enqueue: 111" << endl;
  l.enqueue(111);
  cout << "Expected empty: 0 (FALSE)" << endl;
  cout << "Actual empty: " << l.empty() << endl << endl;
  assert(l.empty() == 0);

  cout << "Expected size: 1" << endl;
  cout << "Actual size: " << l.size() << endl << endl;
  assert(l.size() == 1);

  cout << "Expected top value: 111" << endl;
  cout << "Actual top value: " << l.top() << endl << endl;
  assert(l.top() == 111);
  
  cout << "Enqueue: 222" << endl;
  l.enqueue(222);
  cout << "Expected empty: 0 (FALSE)" << endl;
  cout << "Actual empty: " << l.empty() << endl << endl;
  assert(l.empty() == 0);

  cout << "Expected size: 2" << endl;
  cout << "Actual size: " << l.size() << endl << endl;
  assert(l.size() == 2);

  cout << "Expected top value: 222" << endl;
  cout << "Actual top value: " << l.top() << endl << endl;
  assert(l.top() == 222);
  l.enqueue(333); l.enqueue(444); l.enqueue(555);
  
  
  cout << "Expected size: 5" << endl;
  cout << "Actual size: " << l.size() << endl << endl;
  assert(l.size() == 5);

  cout << "Dequeue" << endl;
  tempInt = l.dequeue();
  cout << "Expected value: 555" << endl;
  cout << "Actual value: " << tempInt << endl << endl;
  assert(tempInt == 555);

  cout << "Dequeue" << endl;
  tempInt = l.dequeue();
  cout << "Expected value: 444" << endl;
  cout << "Actual value: " << tempInt << endl << endl;
  assert(tempInt == 444);

  l.clear();
  cout << "Expected size: 0" << endl;
  cout << "Acutual size: " << l.size() << endl << endl;
  assert(l.size() == 0);
  
  cout << "Insert 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144" << endl << endl;
  
  int intAry[10] = {1, 2, 3, 5, 4, 6, 10, 8, 9, 7};
  for(int i = 10; i != 0; i--)
    l.enqueue(intAry[i-1]);
  
  for (int i = 10; i != 0; i--)
    assert(l.dequeue() == i);

  for(int i = 10; i != 0; i--)
    l.enqueue(intAry[i-1]);

  // object copy testing
  {
    PriorityQueue<int> listCopy = l;
    cout << "Expected empty: 0 (FALSE)" << endl;
    cout << "Actual empty: " << listCopy.empty() << endl << endl;
    assert(listCopy.empty() == 0);
    cout << "Expected size: 10" << endl;
    cout << "Actual size: " << listCopy.size() << endl << endl;
    assert(listCopy.size() == 10);
    cout << "top element value" << endl;
    cout << "Expected top value: 10" << endl;
    cout << "Actual top value: " << listCopy.top() << endl << endl;
    assert(listCopy.top() == 10);
    listCopy.dequeue();
    assert(listCopy.top() == 9);
    for (int i = 9; i != 0; i--)
      assert(listCopy.dequeue() == i);
  }
  
  // object assignment testing
  {
    PriorityQueue<int> listCopy; listCopy = l;
    cout << "Expected empty: 0 (FALSE)" << endl;
    cout << "Actual empty: " << listCopy.empty() << endl << endl;
    assert(listCopy.empty() == 0);
    cout << "Expected size: 10" << endl;
    cout << "Actual size: " << listCopy.size() << endl << endl;
    assert(listCopy.size() == 10);
    cout << "top element value" << endl;
    cout << "Expected top value: 10" << endl;
    cout << "Actual top value: " << listCopy.top() << endl << endl;
    assert(listCopy.top() == 10);
    listCopy.dequeue();
    assert(listCopy.top() == 9);
    for (int i = 9; i != 0; i--)
      assert(listCopy.dequeue() == i);
  }
  
  // const object assignment testing
  {
    const PriorityQueue<int> listCopy = l;
    cout << "Expected empty: 0 (FALSE)" << endl;
    cout << "Actual empty: " << listCopy.empty() << endl << endl;
    assert(listCopy.empty() == 0);
    cout << "Expected size: 10" << endl;
    cout << "Actual size: " << listCopy.size() << endl << endl;
    assert(listCopy.size() == 10);
  }
}
// Lab 10a, Write And Test The ListedList Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include "LinkedList.h"
#include "LinkedList.h" // testing ifndef

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 10a, Write And Test The ListedList Class Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  int tempInt;
  
  LinkedList<int> l;
  
  cout << "Expected isEmpty: 1 (TRUE)" << endl;
  cout << "Actual isEmpty: " << l.isEmpty() << endl << endl;
  assert(l.isEmpty() == 1);
  
  cout << "Expected length: 0" << endl;
  cout << "Actual length: " << l.length() << endl << endl;
  assert(l.length() == 0);
  
  
  cout << "insert: 111" << endl;
  l.insert(111);
  cout << "Expected isEmpty: 0 (FALSE)" << endl;
  cout << "Actual isEmpty: " << l.isEmpty() << endl << endl;
  assert(l.isEmpty() == 0);

  cout << "Expected length: 1" << endl;
  cout << "Actual length: " << l.length() << endl << endl;
  assert(l.length() == 1);

  cout << "first element test" << endl;
  assert(l.first(tempInt) == 1);
  cout << "Expected value: 111" << endl;
  cout << "Actual value: " << tempInt << endl << endl;
  assert(tempInt == 111);
  
  cout << "insert: 222" << endl;
  l.insert(222);
  cout << "Expected isEmpty: 0 (FALSE)" << endl;
  cout << "Actual isEmpty: " << l.isEmpty() << endl << endl;
  assert(l.isEmpty() == 0);

  cout << "Expected length: 2" << endl;
  cout << "Actual length: " << l.length() << endl << endl;
  assert(l.length() == 2);

  cout << "first element test" << endl;
  assert(l.first(tempInt) == 1);
  cout << "Expected value: 222" << endl;
  cout << "Actual value: " << tempInt << endl << endl;
  assert(tempInt == 222);
  l.insert(333); l.insert(444); l.insert(555);
  
  
  cout << "Expected length: 5" << endl;
  cout << "Actual length: " << l.length() << endl << endl;
  assert(l.length() == 5);

  cout << "Expected find 333: 1 (TRUE)" << endl;
  cout << "Actual find 333: " << l.find(333) << endl << endl;
  assert(l.find(333) == 1);
  
  cout << "Expected find 4444: 0 (FALSE)" << endl;
  cout << "Actual find 4444: " << l.find(4444) << endl << endl;
  assert(l.find(4444) == 0);

  cout << "get element of [2]" << endl;
  tempInt = l[2];
  cout << "Expected value: 333" << endl;
  cout << "Actual value: " << tempInt << endl << endl;
  assert(tempInt == 333);

  cout << "Expected l[10]: error" << endl;
  try
  {
    tempInt = l[10];
    cout << tempInt << endl << endl;
  }
  catch (...)
  {
    cout << "Error supposed to be found. Found!" << endl << endl;
  }
  
  cout << "Remove value: 333" << endl;
  tempInt = 333;
  assert(l.remove(tempInt) == 1);

  cout << "Expected replace(15) return: 1 (TRUE)" << endl;
  cout << "Actual replace(15) return: " << l.replace(15) << endl;
  assert(l.replace(15) == 1);

  l.makeEmpty();
  cout << "Expected length: 0" << endl;
  cout << "Acutual length: " << l.length() << endl << endl;
  assert(l.length() == 0);
  
  cout << "Insert 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144" << endl << endl;
  
  int intAry[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for(int i = 10; i != 0; i--)
    l.insert(intAry[i-1]);
  
  // object copy testing
  {
    LinkedList<int> listCopy = l;
    cout << "Expected isEmpty: 0 (FALSE)" << endl;
    cout << "Actual isEmpty: " << listCopy.isEmpty() << endl << endl;
    assert(listCopy.isEmpty() == 0);
    cout << "Expected length: 10" << endl;
    cout << "Actual length: " << listCopy.length() << endl << endl;
    assert(listCopy.length() == 10);
    cout << "first element value" << endl;
    cout << "Expected value: 1" << endl;
    cout << "Actual value: " << listCopy.first(tempInt) << endl << endl;
    assert(listCopy.first(tempInt) == 1); assert(tempInt == 1);
    tempInt = 5;
    assert(listCopy.find(tempInt) == 1);
    assert(listCopy.getNext(tempInt) == 1); assert(tempInt == 6);
  }
  
  // object assignment testing
  {
    LinkedList<int> listCopy; listCopy = l;
    cout << "Expected isEmpty: 0 (FALSE)" << endl;
    cout << "Actual isEmpty: " << listCopy.isEmpty() << endl << endl;
    assert(listCopy.isEmpty() == 0);
    cout << "Expected length: 10" << endl;
    cout << "Actual length: " << listCopy.length() << endl << endl;
    assert(listCopy.length() == 10);
    cout << "first element value" << endl;
    cout << "Expected value: 1" << endl;
    cout << "Actual value: " << listCopy.first(tempInt) << endl << endl;
    assert(listCopy.first(tempInt) == 1); assert(tempInt == 1);
    tempInt = 5;
    assert(listCopy.find(tempInt) == 1);
    assert(listCopy.getNext(tempInt) == 1); assert(tempInt == 6);
  }
  
  // const object assignment testing
  {
    const LinkedList<int> listCopy = l;
    cout << "Expected isEmpty: 0 (FALSE)" << endl;
    cout << "Actual isEmpty: " << listCopy.isEmpty() << endl << endl;
    assert(listCopy.isEmpty() == 0);
    cout << "Expected length: 10" << endl;
    cout << "Actual length: " << listCopy.length() << endl << endl;
    assert(listCopy.length() == 10);
  }
}
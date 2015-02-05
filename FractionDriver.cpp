// Lab 2a, Writing Overloading Operators
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream> 
using namespace std;

#include <cassert>

#include "Fraction.h"
#include "Fraction.h" // Testing ifndef

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 2a, Writing Overloading Operators"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  int denominator, numerator;
  bool test;

  Fraction a, b;

  denominator = 4; numerator = 1;
  a.denominator = denominator;
  a.numerator = numerator;
  denominator = 4; numerator = 1;
  b.denominator = denominator;
  b.numerator = numerator;
  cout << "a fraction : 1/4 \n";
  cout << "b fraction : 1/4 \n";
  a = a + b;
  cout << "Testing operator +\n";
  cout << "Expected value: 2/4 \n";
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(2 == a.numerator);
  assert(4 == a.denominator);

  denominator = 2; numerator = 1;
  a.denominator = denominator;
  a.numerator = numerator;
  denominator = 8; numerator = 1;
  b.denominator = denominator;
  b.numerator = numerator;
  cout << "a fraction : 1/2 \n";
  cout << "b fraction : 1/8 \n";
  a = a + b;
  cout << "Testing operator +\n";
  cout << "Expected value: 10/16 \n";
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(10 == a.numerator);
  assert(16 == a.denominator);

  denominator = 5; numerator = 3;
  a.denominator = denominator;
  a.numerator = numerator;
  denominator = 8; numerator = 5;
  b.denominator = denominator;
  b.numerator = numerator;
  cout << "a fraction : 3/5 \n";
  cout << "b fraction : 5/8 \n";
  a = a + b;
  cout << "Testing operator +\n";
  cout << "Expected value: 49/40 \n";
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(49 == a.numerator);
  assert(40 == a.denominator);

  denominator = 2; numerator = 1;
  a.denominator = denominator;
  a.numerator = numerator;
  denominator = 8; numerator = 1;
  b.denominator = denominator;
  b.numerator = numerator;
  cout << "a fraction : 1/2 \n";
  cout << "b fraction : 1/8 \n";
  a = a * b;
  cout << "Testing operator *\n";
  cout << "Expected value: 1/16 \n";
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(1 == a.numerator);
  assert(16 == a.denominator);

  denominator = 19; numerator = 3;
  a.denominator = denominator;
  a.numerator = numerator;
  denominator = 2; numerator = 1;
  b.denominator = denominator;
  b.numerator = numerator;
  cout << "a fraction : 3/19 \n";
  cout << "b fraction : 1/2 \n";
  a = a * b;
  cout << "Testing operator *\n";
  cout << "Expected value: 3/38 \n";
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(3 == a.numerator);
  assert(38 == a.denominator);
  
  denominator = 2; numerator = 1;
  a.denominator = denominator;
  a.numerator = numerator;
  denominator = 8; numerator = 1;
  b.denominator = denominator;
  b.numerator = numerator;
  cout << "a fraction : 1/2 \n";
  cout << "b fraction : 1/8 \n";
  cout << "Testing operator a > b\n";
  cout << "Expected value: 1\n";
  test = a > b;
  cout << "Acutal value: " << test << "\n\n";
  assert(true == a > b);

  denominator = 7; numerator = 5;
  a.denominator = denominator;
  a.numerator = numerator;
  denominator = 16; numerator = 15;
  b.denominator = denominator;
  b.numerator = numerator;
  cout << "a fraction : 5/7 \n";
  cout << "b fraction : 15/16 \n";
  cout << "Testing operator a > b\n";
  cout << "Expected value: 0\n";
  test = a > b;
  cout << "Acutal value: " << test << "\n\n";
  assert(0 == a > b);

  denominator = 2; numerator = 1;
  a.denominator = denominator;
  a.numerator = numerator;
  cout << "a fraction : 1/2 \n";
  cout << "Testing operator a * 3\n";
  cout << "Expected value: 3/2\n";
  a = a * 3;
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(3 == a.numerator);
  assert(2 == a.denominator);

  denominator = 6; numerator = 34;
  a.denominator = denominator;
  a.numerator = numerator;
  cout << "a fraction : 34/6 \n";
  cout << "Testing operator a * 3\n";
  cout << "Expected value: 102/6\n";
  a = a * 3;
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(102 == a.numerator);
  assert(6 == a.denominator);

  denominator = 2; numerator = 1;
  a.denominator = denominator;
  a.numerator = numerator;
  cout << "a fraction : 1/2 \n";
  cout << "Testing operator 4 * a\n";
  cout << "Expected value: 4/2\n";
  a = 4 * a;
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(4 == a.numerator);
  assert(2 == a.denominator);

  denominator = 93; numerator = 37;
  a.denominator = denominator;
  a.numerator = numerator;
  cout << "a fraction : 37/93 \n";
  cout << "Testing operator 3 * a\n";
  cout << "Expected value: 111/93\n";
  a = 3 * a;
  cout << "Acutal value: " << a.numerator << "/" << a.denominator << "\n\n";
  assert(111 == a.numerator);
  assert(93 == a.denominator);

  //object copy test
  Fraction copy = a;
  assert(copy.denominator == a.denominator);
  assert(copy.numerator == a.numerator);
  cout << "Object copy test passed!\n";

  //object assignment test
  Fraction copy2; copy2 = a;
  assert(copy2.denominator == a.denominator);
  assert(copy2.numerator == a.numerator);
  cout << "Object assignment test passed!\n";
}
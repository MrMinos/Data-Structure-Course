// Lab 3c, const And Constructors, Part 3
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include "Rectangle.h"
#include "Rectangle.h"  // the  test

#include "Fraction.h"

#include <iostream>
using namespace std;

#include <cassert>

int main() 
{
  cout << "Lab 3c, const And Constructors, Part 3"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  float length_f, width_f;
  Fraction length_frac, width_frac, x, y;

  Rectangle<float> testfloat;
  Rectangle<Fraction> testfraction;

  length_f = 1.3;
  width_f = 2.4;
  testfloat.setLength(length_f);
  testfloat.setWidth(width_f);
  cout << "Test length_greater_than_width \n";
  cout << "Length: " << length_f << ", Width: " << width_f << "\n";
  cout << "Expected value: False\n";
  cout << "Result: " << testfloat.length_greater_than_width() << "\n\n";
  assert(false == testfloat.length_greater_than_width());
  cout << "Test getPerimeter \n";
  cout << "Expected value: 7.4\n";
  cout << "Result: " << testfloat.getPerimeter() << "\n\n";
  assert(7.41 >= testfloat.getPerimeter());
  assert(7.4 <= testfloat.getPerimeter());
  cout << "Test getArea \n";
  cout << "Expected value: 3.12\n";
  cout << "Result: " << testfloat.getArea() << "\n\n";
  assert(3.121 >= testfloat.getArea());
  assert(3.12 <= testfloat.getArea());

  length_f = 244.294;
  width_f = 199.32;
  testfloat.setLength(length_f);
  testfloat.setWidth(width_f);
  cout << "Test length_greater_than_width \n";
  cout << "Length: " << length_f << ", Width: " << width_f << "\n";
  cout << "Expected value: True\n";
  cout << "Result: " << testfloat.length_greater_than_width() << "\n\n";
  assert(true == testfloat.length_greater_than_width());
  cout << "Test getPerimeter \n";
  cout << "Expected value: 887.228\n";
  cout << "Result: " << testfloat.getPerimeter() << "\n\n";
  assert(887.229 >= testfloat.getPerimeter());
  assert(887.227 <= testfloat.getPerimeter());
  cout << "Test getArea \n";
  cout << "Expected value: 48692.68008\n";
  cout << "Result: " << testfloat.getArea() << "\n\n";
  assert(48692.7 >= testfloat.getArea());
  assert(48692.6 <= testfloat.getArea());

  length_frac.denominator = 48; length_frac.numerator = 25;
  width_frac.denominator = 38; width_frac.numerator = 59;
  testfraction.setLength(length_frac);
  testfraction.setWidth(width_frac);
  cout << "Test length_greater_than_width \n";
  cout << "Length: " << length_frac.numerator << "/" << length_frac.denominator << "\n";
  cout << "Width: " << width_frac.numerator << "/" << width_frac.denominator << "\n";
  cout << "Expected value: False\n";
  cout << "Result: " << testfraction.length_greater_than_width() << "\n\n";
  assert(false == testfraction.length_greater_than_width());
  cout << "Test getPerimeter \n";
  cout << "Expected value: 7564/1824\n";
  x = testfraction.getPerimeter();
  cout << "Result: " << x.numerator << "/" << x.denominator << "\n\n";
  assert(7564 == x.numerator);
  assert(1824 == x.denominator);
  cout << "Test getArea \n";
  cout << "Expected value: 1475/1824\n";
  x = testfraction.getArea();
  cout << "Result: " << x.numerator << "/" << x.denominator << "\n\n";
  assert(1475 == x.numerator);
  assert(1824 == x.denominator);

  length_frac.denominator = 972; length_frac.numerator = 888;
  width_frac.denominator = 2848; width_frac.numerator = 1288;
  testfraction.setLength(length_frac);
  testfraction.setWidth(width_frac);
  cout << "Test length_greater_than_width \n";
  cout << "Length: " << length_frac.numerator << "/" << length_frac.denominator << "\n";
  cout << "Width: " << width_frac.numerator << "/" << width_frac.denominator << "\n";
  cout << "Expected value: True\n";
  cout << "Result: " << testfraction.length_greater_than_width() << "\n\n";
  assert(true == testfraction.length_greater_than_width());
  cout << "Test getPerimeter \n";
  cout << "Expected value: 7561920/2768256\n";
  x = testfraction.getPerimeter();
  cout << "Result: " << x.numerator << "/" << x.denominator << "\n\n";
  assert(7561920 == x.numerator);
  assert(2768256 == x.denominator);
  cout << "Test getArea \n";
  cout << "Expected value: 1143744/2768256\n";
  x = testfraction.getArea();
  cout << "Result: " << x.numerator << "/" << x.denominator << "\n\n";
  assert(1143744 == x.numerator);
  assert(2768256 == x.denominator);

  //2 data constructor test - float
  testfloat = Rectangle<float>(199.32, 244.294);
  cout << "Test length_greater_than_width \n";
  cout << "Length: " << length_f << ", Width: " << width_f << "\n";
  cout << "Expected value: True\n";
  cout << "Result: " << testfloat.length_greater_than_width() << "\n\n";
  assert(true == testfloat.length_greater_than_width());
  cout << "Test getPerimeter \n";
  cout << "Expected value: 887.228\n";
  cout << "Result: " << testfloat.getPerimeter() << "\n\n";
  assert(887.229 >= testfloat.getPerimeter());
  assert(887.227 <= testfloat.getPerimeter());
  cout << "Test getArea \n";
  cout << "Expected value: 48692.68008\n";
  cout << "Result: " << testfloat.getArea() << "\n\n";
  assert(48692.7 >= testfloat.getArea());
  assert(48692.6 <= testfloat.getArea());

  //2 data constructor test - Fraction
  length_frac.denominator = 48; length_frac.numerator = 25;
  width_frac.denominator = 38; width_frac.numerator = 59;
  testfraction = Rectangle<Fraction>(width_frac, length_frac);
  cout << "Test length_greater_than_width \n";
  cout << "Length: " << length_frac.numerator << "/" << length_frac.denominator << "\n";
  cout << "Width: " << width_frac.numerator << "/" << width_frac.denominator << "\n";
  cout << "Expected value: False\n";
  cout << "Result: " << testfraction.length_greater_than_width() << "\n\n";
  assert(false == testfraction.length_greater_than_width());
  cout << "Test getPerimeter \n";
  cout << "Expected value: 7564/1824\n";
  x = testfraction.getPerimeter();
  cout << "Result: " << x.numerator << "/" << x.denominator << "\n\n";
  assert(7564 == x.numerator);
  assert(1824 == x.denominator);
  cout << "Test getArea \n";
  cout << "Expected value: 1475/1824\n";
  x = testfraction.getArea();
  cout << "Result: " << x.numerator << "/" << x.denominator << "\n\n";
  assert(1475 == x.numerator);
  assert(1824 == x.denominator);

  //object copy test
  Rectangle<float> copy = testfloat;
  Rectangle<Fraction> copy2 = testfraction;
  assert(copy.length_greater_than_width() == testfloat.length_greater_than_width());
  assert(copy.getPerimeter() == testfloat.getPerimeter());
  assert(copy.getArea() == testfloat.getArea());
  assert(copy2.length_greater_than_width() == testfraction.length_greater_than_width());
  x = copy2.getPerimeter();
  y = testfraction.getPerimeter();
  assert(x.numerator == y.numerator);
  assert(x.denominator == y.denominator);

  x = copy2.getArea();
  y = testfraction.getArea();
  assert(x.numerator == y.numerator);
  assert(x.denominator == y.denominator);
  cout << "object copy test passed!\n";

  //object assignment test
  Rectangle<float> copy3; copy3 = testfloat;
  Rectangle<Fraction> copy4; copy4 = testfraction;
  assert(copy3.length_greater_than_width() == testfloat.length_greater_than_width());
  assert(copy3.getPerimeter() == testfloat.getPerimeter());
  assert(copy3.getArea() == testfloat.getArea());
  assert(copy4.length_greater_than_width() == testfraction.length_greater_than_width());
  x = copy4.getPerimeter();
  y = testfraction.getPerimeter();
  assert(x.numerator == y.numerator);
  assert(x.denominator == y.denominator);

  x = copy4.getArea();
  y = testfraction.getArea();
  assert(x.numerator == y.numerator);
  assert(x.denominator == y.denominator);
  cout << "object assignment test passed!\n";
}
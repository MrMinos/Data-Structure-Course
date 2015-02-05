// Lab 2a, Writing Overloading Operators
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include "Fraction.h"

Fraction operator + (Fraction l, Fraction r)
{
  Fraction t;
  if (l.denominator == r.denominator)
  {
    t.numerator = l.numerator + r.numerator;
    t.denominator = l.denominator;
  }
  else
  {
    t.denominator = l.denominator * r.denominator;
    t.numerator = l.numerator * r.denominator + r.numerator * l.denominator;
  }
  return t;
}

Fraction operator * (Fraction l, Fraction r)
{
  Fraction t;
  t.denominator = l.denominator * r.denominator;
  t.numerator = l.numerator * r.numerator;
  return t;
}

bool operator > (Fraction l, Fraction r)
{
  return ((double) l.numerator / l.denominator) > ((double) r.numerator / r.denominator);
}

Fraction operator * (int a, Fraction t)
{
  t.numerator = a * t.numerator;
  return t;
}
Fraction operator * (Fraction t, int a)
{
  t.numerator = a * t.numerator;
  return t;
}
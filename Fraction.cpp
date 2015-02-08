// Lab 3c, const And Constructors, Part 3
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include "Fraction.h"

Fraction operator + (const Fraction& l, const Fraction& r)
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

Fraction operator * (const Fraction& l, const Fraction& r)
{
  Fraction t;
  t.denominator = l.denominator * r.denominator;
  t.numerator = l.numerator * r.numerator;
  return t;
}

bool Fraction::operator>(const Fraction& l, const Fraction& r) const
{
  return ((double) l.numerator / l.denominator) > ((double) r.numerator / r.denominator);
}

Fraction operator * (const int a, Fraction t)
{
  t.numerator = a * t.numerator;
  return t;
}
Fraction operator * (Fraction t, const int a)
{
  t.numerator = a * t.numerator;
  return t;
}
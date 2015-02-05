// Lab 2a, Writing Overloading Operators
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
  int denominator = 1;
  int numerator = 0;
};

Fraction operator + (Fraction, Fraction);
Fraction operator * (Fraction, Fraction);
bool operator > (Fraction, Fraction);
Fraction operator * (int, Fraction);
Fraction operator * (Fraction, int);

#endif
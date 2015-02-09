// Lab 3c, const And Constructors, Part 3
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

Fraction operator + (const Fraction&, const Fraction&);
Fraction operator * (const Fraction&, const Fraction&);
bool operator > (const Fraction&, const Fraction&);
Fraction operator * (const int, Fraction);
Fraction operator * (Fraction, const int);


#endif
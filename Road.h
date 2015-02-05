// Lab 3a, const And Constructors, Part 1
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#ifndef Road_h
#define Road_h

class Road
{
  double width;
  double length;

public:
  Road (double, double);
  double asphalt (const double) const;
  void SetWidth(const double);
  double GetWidth() const;
  void SetLength(const double);
  double GetLength() const;
};
#endif
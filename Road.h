// Lab 1a, Class Programming And Testing
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
  double asphalt (double) const;
  void SetWidth(double);
  double GetWidth() const;
  void SetLength(double);
  double GetLength() const;
};
#endif
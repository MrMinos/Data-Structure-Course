// Lab 3a, const And Constructors, Part 1
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include "Road.h"

Road::Road (double w, double l)
{
  width = w; length = l;
}

double Road::asphalt (const double thick) const
{
  return width * length * (thick / 12);
}

void Road::SetWidth(const double w)
{
  width = w;
}

double Road::GetWidth() const
{
  return width;
}

void Road::SetLength(const double l)
{
  length = l * 5280;
}

double Road::GetLength() const
{
  return length / 5280;
}



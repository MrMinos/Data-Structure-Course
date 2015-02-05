// Lab 1a, Class Programming And Testing
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include "Road.h"


double Road::asphalt (double thick)
{
  return width * length * (thick / 12);
}

void Road::SetWidth(double w)
{
  width = w;
}

double Road::GetWidth()
{
  return width;
}

void Road::SetLength(double l)
{
  length = l * 5280;
}

double Road::GetLength()
{
  return length / 5280;
}



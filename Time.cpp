// Lab 3b, const And Constructors, Part 2
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include "Time.h"

Time::Time()
{
}

Time::Time(const int h, const int m, const int s)
{
  hours = h * 3600;
  minutes = m * 60;
  seconds = s;
}

void Time::setHours(const int h)
{
  hours = h * 3600;
}

void Time::setMinutes(const int m)
{
  minutes = m * 60;
}

void Time::setSeconds(const int s)
{
  seconds = s;
}

double Time::timeInHours() const
{
  return ((double) (hours + minutes + seconds) / 3600);
}

double Time::timeInMinutes() const
{
  return ((double) (hours + minutes + seconds) / 60);
}

int Time::timeInSeconds() const
{
  return (hours + minutes + seconds);
}
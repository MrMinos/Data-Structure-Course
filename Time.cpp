// Lab 1b, More Class Programming And Testing
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include "Time.h"

void Time::setHours(int h)
{
  hours = h * 3600;
}

void Time::setMinutes(int m)
{
  minutes = m * 60;
}

void Time::setSeconds(int s)
{
  seconds = s;
}

double Time::timeInHours()
{
  return ((double) (hours + minutes + seconds) / 3600 );
}

double Time::timeInMinutes()
{
  return ((double) (hours + minutes + seconds) / 60);
}

int Time::timeInSeconds()
{
  return (hours + minutes + seconds);
}
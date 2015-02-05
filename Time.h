// Lab 1b, More Class Programming And Testing
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#ifndef Time_h
#define Time_h

class Time
{
  int hours;
  int minutes;
  int seconds;

public:
  void setHours(int);
  void setMinutes(int);
  void setSeconds(int);
  double timeInHours();
  double timeInMinutes();
  int timeInSeconds();
};
#endif
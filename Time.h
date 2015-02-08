// Lab 3b, const And Constructors, Part 2
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
  Time();
  Time(const int, const int, const int);
  void setHours(const int);
  void setMinutes(const int);
  void setSeconds(const int);
  double timeInHours() const;
  double timeInMinutes() const;
  int timeInSeconds() const;
};
#endif
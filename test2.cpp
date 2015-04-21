// Lab 12b, The "Perform A Simple Timing Study" Program
// Programmer: Hojoon Lee
// Editor(s) used: xcode
// Compiler(s) used: xcode

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <cmath>
#include "PriorityQueue.h"
using namespace std;

int main()
{
  // print name and assignment's title
  cout << "Lab 12b, The \"Perform A Simple Timing Study\" Program \n";
  cout << "Programmer: Hojoon Lee\n";
  cout << "Editor(s) used: xcode\n";
  cout << "Compiler(s) used: xcode\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  //BigOh enqueue
  {
    cout << "BigOh Enqueue" << endl;
    string bigOh = "O(log n)";
    int n = 7000000;
    int elapsedTimeTicksNorm = 0;
    int expectedTimeTicks = 0;
    int REPS = n * 0.01;
    
    for(int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
      PriorityQueue<int> p(n * 2);
      
      for(int i = n; i > 0; i--)
        p.enqueue(i);
      
      assert(p.size() == n);
      
      clock_t startTime = clock();
      
      for(int rep = 1; rep <= REPS; rep++)
      {
        p.enqueue(n + rep);
      }
      
      clock_t endTime = clock();
      
      assert(p.size() == n + REPS);
      
      for(int i = 0; i < n + REPS - 1; i++)
      {
        int pop = p.dequeue();
        int top = p.top();
        assert(pop > top);
      }
      
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      
      if(cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if(bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if(bigOh == "O(log n)")
        expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if(bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if(bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if(bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
      
      cout << elapsedTimeTicks;
      
      if(cycle == 0)
        cout << " (expected " << bigOh << ')';
      else
        cout << " (expected " << expectedTimeTicks << ')';
      
      cout << " for n = " << n << endl;
    }
  }
  
  //BigOh dequeue
  {
    cout << endl << "BigOh Dequeue" << endl;
    string bigOh = "O(log n)";
    int n = 5000000;
    int elapsedTimeTicksNorm = 0;
    int expectedTimeTicks = 0;
    int REPS = n * 0.1;
    
    for(int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
      PriorityQueue<int> p(n);
      
      for(int i = n; i > 0; i--)
        p.enqueue(i);
      
      assert(p.size() == n);
      
      clock_t startTime = clock();
      
      for(int rep = 1; rep <= REPS; rep++)
      {
        p.dequeue();
      }
      
      clock_t endTime = clock();
      
      assert(p.size() == n - REPS);
      
      for(int i = 0; i < n - REPS - 1; i++)
      {
        int pop = p.dequeue();
        int top = p.top();
        assert(pop > top);
      }
      
      
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      
      if(cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if(bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if(bigOh == "O(log n)")
        expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if(bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if(bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if(bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
      
      cout << elapsedTimeTicks;
      
      if(cycle == 0)
        cout << " (expected " << bigOh << ')';
      else
        cout << " (expected " << expectedTimeTicks << ')';
      
      cout << " for n = " << n << endl;
    }
  }
  
  
}
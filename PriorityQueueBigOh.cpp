// Lab 12b, Perform A Simple Timing Study
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <string>
using namespace std;

#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "PriorityQueue.h"

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 12b, Perform A Simple Timing Study\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  int tempInt;
  int N = 5000000;
  const int REPS = 70000;

  for(int select = 1; select < 3; select++)
  {
    int n = N;
    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;
    
    if(select == 1)
      cout << "Enqueue, O(log n)" << endl;
    
    if(select == 2)
      cout << "Dequeue, O(log n)" << endl;
    
    for(int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
      PriorityQueue<double> l(2 * n + REPS);
      
      for(int i = n; i > 0; i--)
        l.enqueue(i);
      
      assert(l.size() == n);
      
      string bigOh = "O(log n)";
      clock_t startTime = clock();
      
      if(select == 1)
      {
        for(int r = n+1; r < n+REPS; r++)
          l.enqueue(r);
      }
      
      if(select == 2)
      {
        for(int r = 0; r < REPS; r++)
          l.dequeue();
      }
      
      clock_t endTime = clock();
      
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      
      if (select == 1)
      {
        for (int i = n+REPS-1; i > 0; i--)
          assert(l.dequeue() == i);
      }

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
      
      cout << "  " << elapsedTimeTicks;;
      
      if(cycle == 0)
        cout << " (expected " << bigOh << ')';
      else
        cout << " (expected " << expectedTimeTicks << ')';
      
      cout << " for n=" << n << endl;
    }
    cout << endl;
  }
}
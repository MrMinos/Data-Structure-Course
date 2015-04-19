// Lab 10c, Perform Performance Confirmation On The ListedList Class Template
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

#include "LinkedList.h"
#include "LinkedList.h"

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 10c, Perform Performance Confirmation On The ListedList Class Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  int tempInt;
  int N = 50000;
  int randMax = 1000;
  const int REPS = 400000;
  srand(time(0));
  double prime = (rand() % randMax + 1);
  
  for(int select = 1; select < 5; select++)
  {
    int n = N;
    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;
    
    if(select == 1)
      cout << "Operator[] assignment at zeroth index, O(1)" << endl;
    
    if(select == 2)
      cout << "Operator[] assignment at 100th index, O(1)" << endl;
    
    if(select == 3)
      cout << "Iteration from first to last using operator[], O(n)" << endl;
    
    if(select == 4)
      cout << "Length query, O(1)" << endl;
    
    for(int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
      LinkedList<double> l;
      
      for(int i = 0; i < n; i++)
        l.insert((rand() % randMax));
      
      assert(l.length() == n);
      
      string bigOh = "O(1)";
      clock_t startTime = clock();
      
      if(select == 1)
      {
        for(int r = 0; r < REPS; r++)
          l[0] = (rand() % randMax);
      }
      
      if(select == 2)
      {
        for(int r = 0; r < REPS; r++)
          l[100] = (rand() % randMax);
      }
      
      if(select == 3)
      {
        bigOh = "O(n)";
        for(int i = 0; i < l.length(); i++) l[i];
      }
      
      if(select == 4)
      {
        for(int r = 0; r < REPS; r++)
          tempInt = l.length();
      }
      
      clock_t endTime = clock();
      
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
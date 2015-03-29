// Lab 9b,  Perform A Timing Study On Nested For-Loop Sorting
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <cassert>
#include <ctime>
#include <cmath>

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 9b,  Perform A Timing Study On Nested For-Loop Sorting\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  int n = 2000;
  string bigOh = "O(n squared)";
  double tmp;
  int elaspsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  double* array;

  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
  	srand(time(NULL)); rand();

  	array = new double[n];
  	for (int i = 0; i < n; i++) array[i] = rand();

  	clock_t startTime = clock();

  	for (int i = 0; i < n; i++)
  	{
  	  tmp = array[i];
  	  for (int j = i + 1; j < n; j++)
  	  {
  	  	if(array[j] < array[i])
  	  	{
  	  	  tmp = array[j];
  	  	  array[j] = array[i];
  	  	  array[i] = tmp;
  	  	}
  	  }
  	}

  	clock_t endTime = clock();
  	for (int i = 1; i < n; i++) assert (array[i-1] <= array[i]);

  	delete [] array;

  	long elaspsedTimeTicks = (long)(endTime - startTime);
  	double factor  = pow(2.0, cycle);

  	if(cycle == 0)
  		elaspsedTimeTicksNorm = elaspsedTimeTicks;
  	else if(bigOh == "O(1)")
  		expectedTimeTicks = elaspsedTimeTicksNorm;
  	else if(bigOh == "O(log n)")
  		expectedTimeTicks = log(double(n)) / log(n / factor) * elaspsedTimeTicksNorm;
  	else if (bigOh == "O(n)")
  		expectedTimeTicks = factor * elaspsedTimeTicksNorm;
  	else if(bigOh == "O(n log n)")
  		expectedTimeTicks = factor * log(double(n)) / log (n / factor) * elaspsedTimeTicksNorm;
  	else if(bigOh == "O(n squared)")
  		expectedTimeTicks = factor * factor * elaspsedTimeTicksNorm;


  	cout << elaspsedTimeTicks;
  	if(cycle == 0) cout << " (expected " << bigOh << ")";
  	else cout << " (expected " << expectedTimeTicks << ")";
  	cout << " for n=" << n << endl;
  }
}

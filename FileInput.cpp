// Lab 9a, Perform A Simple Timing Study
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
  cout << "Lab 9a, Perform A Simple Timing Study\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  char *token;
  char buf[1000];
  string line;
  const char* const tab = "\t";
  ifstream fin;

  int n = 5000;
  string bigOh = "O(n)";
  int count;

  int elaspsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
  	count = 0;
  	fin.open("dvc-schedule.txt");
  	if (!fin.good()) throw "I/O error";
  	getline(fin, line);

  	clock_t startTime = clock();

 	while(fin.good() && count < n)
	{
      getline(fin, line);
      strcpy(buf, line.c_str());
      if(buf[0] == 0) continue;
    
      const string term(token = strtok(buf, tab));
      const string section(token = strtok(0, tab));
      const string course((token = strtok(0, tab))?token : "");
      const string courseName(course.begin(), course.begin() + course.find('-'));
      count++;
    }

  	clock_t endTime = clock();

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

  	fin.close();
  }
}

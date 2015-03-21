// Lab 8a, Write And Apply A Stack Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <stack>
using namespace std;
#include <cstring>

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 8a, Write And Apply A Stack Templat\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  float num, a, b;
  char buf[100];
  stack<float> calc, calc_out;

  while(1)
  {
    cout << "Enter: ";
    if (!calc.empty()) calc_out = calc;
  while (!calc_out.empty())
  {
    cout << calc_out.top() << " ";
      calc_out.pop();
  }
    cin >> buf;
    if (buf[0] == 'q' || buf[0] == 'Q') return 0;
    else if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/')
    {
      if(calc.size() < 2)
      {
        continue;
      } 
      else
      {
        b = calc.top(); calc.pop(); 
        a = calc.top(); calc.pop();
        switch (buf[0])
        {
          case'+':
            calc.push(a + b);  continue;
          case '-':
            calc.push(a - b);  continue;
          case '*':
            calc.push(a * b);  continue;
          case '/':
            calc.push(a / b);  continue;
        }
      }
    }
    else
    {
      num = atof(buf);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      calc.push(num);
    }
  }
}
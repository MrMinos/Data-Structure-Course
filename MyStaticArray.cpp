// Lab 5a, Write A Static Array Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream> 
using namespace std;

#include "StaticArray.h"

char buf[100];
Array<int, 100> data;

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 5a, Write A Static Array Class Template"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  int select;
  while(data.size()<=data.capacity())
  {
  	cout << "input data: ";
    cin >> buf;
    if(buf[0]=='q' || buf[0]=='Q') 
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << endl << "Data Structure size: " << data.size() << endl;

      cout << "All entered values: ";// << data[i] << ", "
      for (int i = 0; i < data.size(); i++)
      {
        cout << data[i] << " ";
      }

      cout << endl << endl;
      while(1)
      {
        cout << "Search query: ";
        cin >> buf;
        if (buf[0]=='q' || buf[0]=='Q') return 0;
        select = atoi(buf);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int temp = data.lsearch(select);
        cout << "Found data: data[" << temp << "] = " << data[temp] << endl << endl;
      }
    }

    select = atoi(buf);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    data[data.size()] = select;
  }

}

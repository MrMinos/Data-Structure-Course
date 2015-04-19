// Lab 10b, Write And Test The ListedList Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include "LinkedList.h"

static string buf;
LinkedList<int> getElements()
{
  LinkedList<int> numbers;
  int userIn = 0;
  cout << "Type data or \'Q\' to exit: ";
  cin >> buf; cin.ignore(1000, 10);
  if(buf[0] == 'q' || buf[0] == 'Q')
    return numbers;
  userIn = atoi(buf.c_str());
  
  while(1)
  {
    numbers.insert(userIn);
    
    cout << "Type data or \'Q\' to exit: ";
    cin >> buf;
    cin.ignore(1000, 10);
    if(buf[0] == 'q' || buf[0] == 'Q')
      return numbers;
    userIn = atoi(buf.c_str());
  }
  return numbers;
}
void searchFor(LinkedList<int> ar)
{
  int number;
  
  while(1)
  {
    cout << endl << "Search value or \'Q\' to exit: ";
    
    cin >> buf;
    cin.ignore(1000, 10);
    if(buf[0] == 'q' || buf[0] == 'Q')
      break;
    number = atoi(buf.c_str());
    
    if(ar.find(number))
      cout << "==Value " << buf << " found in list." << endl;
    else
      cout << "==Value not found." << endl;
  }
}

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 10b, Write And Test The ListedList Class Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  LinkedList<int> nums;
  nums = getElements();
  if(nums.length() <= 0)
    cout << endl << "==The list contains no values" << endl << endl;
  else
  {
    cout << endl << "==The list: " << nums[0];
    for(int i = 1; i < (nums.length()); i++)
      cout << ", " << nums[i];
  }
  cout << endl;
  searchFor(nums);
}
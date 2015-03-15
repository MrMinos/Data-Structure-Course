// Lab 4b, Introduction To Dynamic Array Doubling And Deallocation
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include "Checkbook.h"
#include <iostream>
using namespace std;

#define DataType double
#define DataInput(...) atof(__VA_ARGS__)
#define initialBalance 0;

char buf[100];
Checkbook <DataType> check(0);

void writeCheck();
void makeDeposit();
void listCheck();

int main() 
{
  cout << "Lab 4b, Introduction To Dynamic Array Doubling And Deallocation"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  int select;
  while(1)
  {
    cout << "================Check==Book================" << endl;
    cout << "1: Get Balance" << endl;
    cout << "2: Write a Check" << endl;
    cout << "3: Make a Deposit" << endl;
    cout << "4: Quit" << endl;
    cout << "5: Other option; List All Checks" << endl;
    cout << "Your Choice: ";
    cin >> buf;
    select = atoi(buf);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "===========================================" << endl << endl;

    switch(select)
    {
      case 1:
        cout << "Your Balance is:" << check.getBalance() << endl;
        cout << "Press ENTER to continue..." << endl;
        cin.get();
        break;
      case 2:
        writeCheck();
        break;
      case 3:
        makeDeposit();
        break;
      case 4:  return 0;
      case 5:
        listCheck();
        break;
    }
  }
}

void writeCheck()
{
  cout << "Check amount: ";
  cin >> buf;
  DataType temp = DataInput(buf);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  check.writeChecks(temp);
  cout << "Check written successfully!" << endl;
  cout << "Press ENTER to continue..." << endl;
  cin.get();
}

void makeDeposit()
{
  cout << "Deposit amount: ";
  cin >> buf;
  DataType temp = DataInput(buf);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  check.makeDeposit(temp);
  cout << "Deposit successful!" << endl;
  cout << "Press ENTER to continue..." << endl;
  cin.get();
}

void listCheck()
{
  if (check.getNumCheckWritten()==0)
  {
  	cout << "No Checks Written" << endl;
  	cout << "Press ENTER to continue..." << endl;
    cin.get();
  	return;
  }
  cout << "List of Checks Written" << endl;
  DataType* list = check.getChecks();
  for (int i = 0; i < check.getNumCheckWritten(); i++)
  {
  	cout << "Check #" << i + 1 << ": " << list[i] << endl;
  }
  delete [] list;
  cout << "Press ENTER to continue..." << endl;
  cin.get();
}
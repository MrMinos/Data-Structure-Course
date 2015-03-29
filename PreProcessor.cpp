// Lab 8c, Use A Stack
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 8c, Use A Stack\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  Program structure would be 
  1. file reading portion, determine the file extension
  2. file parsing portion, a line and then the characters for the special characters?
  3. analyzing the brackets
  4. Reporing any error back, if not ending with no error
  
  //file read
  ifstream fin;
  string filename;

  cout << "Enter filename (H, CPP, JAVA, HTML, or JS): ";
  cin >> filename;
  
  fin.open(filename);
  if (!fin.good()) throw "I/O error";
  getline(fin, line); //Eliminate first line
}
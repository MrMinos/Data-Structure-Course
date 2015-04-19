// Lab 11a, Write And Test The HashTable Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring>
#include <cassert>

#include "HashTable.h"
#include "HashTable.h" //ifndef test

struct Course
{
  string term;
  string section;
  string instructor;
  string course;
  bool operator==(const Course& parameter) const{return(course == parameter.course && term == parameter.term && section == parameter.section)?true:false;}
};

int hashCode(const Course& course)
{
  int index=0;
  string code=course.term+course.section;
  for(int i=0;i<code.length();i++) (index+=(int)code[i]);
  return index;
}

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 11a, Write And Test The HashTable Class Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  HashTable<Course,int,1009> tester(hashCode);
  Course test1, test2, test3;
  vector<Course>keys=tester.keys();
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int lineCount=0;

  test1.term ="Spring 2005"; test1.section = "2603"; test1.instructor = "BULL"; test1.course="SHIT-101";
  tester[test1]=hashCode(test1);
  test2.term ="Spring 2004"; test2.section = "2303"; test2.instructor = "ABC"; test2.course="BLABL-101";
  tester[test2]=hashCode(test2);
  cout << "Expected HashTable Size: 2, Actual Size: " << tester.size() << endl;
  tester.clear();
  cout << "The size of the array is now: " << tester.size() << endl;
  assert(0 == tester.size());

  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good())
  {
  	if(lineCount==101) break;
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue;
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    test1.term=term;
    test1.section=section;
    test1.course=course;
    test1.instructor = instructor;

    tester[test1]; 
    lineCount++;
  }
  fin.close();

  cout << "Total line: " << lineCount << ", Duplicates: " << (lineCount-tester.size()) << endl;
  cout << "Size: "<<tester.size()<<endl;
  assert(tester.size() == 100);
  cout << "Capacity expected value: 807, Actual Value: " << tester.capacity() << endl;
  assert(tester.capacity() == 807);
  tester.clear();
  assert(tester.size() == 0);

  test3.term ="Spring 2015"; test3.section = "2103"; test3.instructor = "RBurns"; test3.course="COMSC-210";
  tester[test3]=hashCode(test3);
  cout << "Expected HashCode Value: 1057 Actual Value: " << tester[test3] << endl;
  assert(1057 == tester[test3]);
  cout << "Size: " << tester.size() << endl;
  tester.deleteKey(test3);
  cout << "Expected value: 0, Actual value: " << tester.size() << endl;
  assert(0 == tester.size());
  
  //object copy test
  {
    HashTable<Course,int,1009>copy = tester;
    assert(copy.size() == tester.size());
    cout << "Copy Size: " << copy.size() << " Actual Size: " << tester.size() << endl;
    cout << "Expected Size: 1" << endl;
    test3.term ="Spring 2015"; test3.section = "8301"; test3.instructor = "Burns"; test3.course="COMSC-210";
    copy[test3]=hashCode(test3);
    cout<<"Actual Size: "<<copy.size()<<endl;
    assert(copy.size() == 1);
    copy.clear();
    cout<<"Expected size: 0, Actual size: "<< copy.size() << endl;
    assert(copy.size() == 0);
  }

  //object assignment test
  {
    HashTable<Course,int,1009>copy(hashCode); copy= tester;
    assert(copy.size() == tester.size());
    cout << "Copy Size: " << copy.size() << " Actual Size: " << tester.size() << endl;
    cout << "Expected Size: 1" << endl;
    test3.term ="Spring 2015"; test3.section = "8301"; test3.instructor = "Burns"; test3.course="COMSC-210";  
    copy[test3]=hashCode(test3);
    cout << "Actual Size: " << copy.size() << endl;
    assert(copy.size() == 1);
    copy.clear();
    cout << "Expected size: 0, Actual size: " << copy.size() << endl;
    assert(copy.size() == 0);
  }
}
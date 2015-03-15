// Lab 6a, Write A Dynamic Array Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
#include <ctime>
#include "DynamicArray.h"

using namespace std;

struct SubjectCode
{
  int sectionCount;
  string section;
  string term;
  string name;
};

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 6a, Write A Dynamic Array Class Template\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Array<SubjectCode> subjectCodes;
  SubjectCode tmp;
  vector<string> dup(1, "");
  char *token;
  char buf[1000];
  string line;
  const char* const tab = "\t";
  int progressbar = 0;
  int courseCount = 0;
  bool check = 0;
  
  ifstream fin;
  clock_t startTime = clock();
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  getline(fin, line); //Eliminate first line
  
  cout << "Progress Bar";
  
  while(fin.good())
  {
    if(progressbar % 1000 == 0)
    {
      cout << ".";
      cout.flush();
    }
    progressbar++;
    check = false;
    
    getline(fin, line);
    strcpy(buf, line.c_str());
    if(buf[0] == 0) continue;
    
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab))?token : "");
    const string courseName(course.begin(), course.begin() + course.find('-'));
    
    tmp.name = courseName;
    tmp.section = section;
    tmp.term = term;
  
    for(int i = 0; i < dup.size(); i++)
    { 
      if((dup[i].compare(0, term.size(), term)) == 0)
      {
        if((dup[i].find(',' + section, 12)) != -1 )
        {
          subjectCodes[0].sectionCount++;
          check = true;
        }
        else
        {
          dup[i] += ',' + section;
        }
        break;
      }
      if(i + 1 == dup.size())
        dup.push_back((string) term + ',' + section);
    }
    
    if(check == false)
    {
      for (int i = 1; i <= courseCount; i++)
      {
        if(subjectCodes[i].name.compare(tmp.name) == 0)
        {
          subjectCodes[i].sectionCount ++;
          check = true;
          break;
        }
      }
    }
    
    if(check == false)
    {
      courseCount++;
      assert(courseCount < 200);
      subjectCodes[courseCount] = tmp;
      subjectCodes[courseCount].sectionCount = 1;
    }
  }
  cout << endl << endl;
  fin.close();
  
  cout << "Total " << courseCount << " classes" << endl << endl;
  for(int i = 1; i <= courseCount; i++)
  {
    int temp = i;
    tmp = subjectCodes[i];
    
    for(int j = i + 1; j <= courseCount; j++)
    {
      if((subjectCodes[j].name.compare(tmp.name)) < 0)
      {
        temp = j;
        tmp = subjectCodes[j];
        subjectCodes[temp] = subjectCodes[i];
        subjectCodes[i] = tmp;
      }
    }
  }
  
  for(int i = 1; i <= courseCount; i++)
    cout << subjectCodes[i].name << ", " << subjectCodes[i].sectionCount << " classes" << endl;
  
  cout << endl;
  cout << "Duplicates: " << subjectCodes[0].sectionCount << endl << endl;
    
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  cout << "Computation Time: " << elapsedSeconds << endl;
  
}
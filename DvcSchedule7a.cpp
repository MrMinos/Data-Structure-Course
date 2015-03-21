// Lab 7a, Write A Linked-List Solution
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
#include <ctime>

using namespace std;

struct SubjectCode
{
  int sectionCount;
  string section;
  string term;
  string name;
};

struct Node
{
  SubjectCode data;
  Node* next;
};

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 7a, Write A Linked-List Solution\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //vector<SubjectCode> subjectCodes;
  Node* root = NULL;
  Node* step = NULL;
  Node* last = NULL;
  SubjectCode tmp;
  vector<string> dup(1, "");
  char *token;
  char buf[1000];
  string line;
  const char* const tab = "\t";
  int progressbar = 0;
  int courseCount = 0;
  bool check = false;
  
  ifstream fin;
  clock_t startTime = clock();
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  getline(fin, line); //Eliminate first line
  
  cout << "Progress Bar";

  root = new Node;
  step = root;
  step->next = NULL;
  root->data.sectionCount = 0;
  tmp.sectionCount = 1;
  
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
          root->data.sectionCount++;
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
      last = step; step = root->next;
      while (step != NULL)
      {
        if (step->data.name.compare(tmp.name) == 0)
        {
          step->data.sectionCount ++;
          check = true;
          step = last;
          break;
        }
        step = step->next;
      }
      step = last;
    }
    
    if(check == false)
    {
      step->next = new Node;
      step = step->next;
      step->next = NULL;
      courseCount++;
      assert(courseCount < 200);
      step->data = tmp;
    }
  }
  cout << endl << endl;
  fin.close();
  
  cout << "Total " << courseCount << " classes" << endl << endl;
  for (step = root->next; step; step = step->next)
  {
    tmp = step->data;

    for (last = step->next; last; last = last->next)
    {
      if((last->data.name.compare(tmp.name)) < 0)
      {
        tmp = last->data;
        last->data = step->data;
        step->data = tmp;
      }
      if(last == NULL) break;
    }
    if(step == NULL) break;
  }
  
  step = root->next;
  while (step != NULL)
  {
    cout << step->data.name << ", " << step->data.sectionCount << " classes" << endl;
    step = step->next;
  }
  cout << endl;
  cout << "Duplicates: " << root->data.sectionCount << endl << endl;
    
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  cout << "Computation Time: " << elapsedSeconds << endl;

  step = root;
  while (step != NULL)
  {
    delete step;
    step = step->next;
  }
  
}
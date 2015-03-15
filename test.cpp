// Lab 7a, The "Write A Linked-List Solution" Program
// Programmer: Hojoon Lee
// Editor(s) used: xcode
// Compiler(s) used: xcode

#include <iostream>
#include <string>
#include <ctime>
#include <deque>
#include <fstream>
using namespace std;

struct SubjectCode
{
  string name;
  int count;
};

struct Node
{
  SubjectCode data;
  Node* next;
};

int main()
{
  // print name and assignment's title
  cout << "Lab 7a, The \"Write A Linked-List Solution\" Program \n";
  cout << "Programmer: Hojoon Lee\n";
  cout << "Editor(s) used: xcode\n";
  cout << "Compiler(s) used: xcode\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  Node *head = 0;
  Node *p = 0;
  Node *prev = 0;
  bool flag = 1;
  SubjectCode temp;
  
  char* token;
  char buf[1000];
  string line;
  const char* const tab = "\t";
  
  ifstream fin;
  clock_t startTime = clock();
  fin.open("dvc-schedule.txt");
  if (!fin.good())
    throw "I/O error";
  getline(fin, line);
  
  int tmpCnt = 0;
  cout << "Progress";
  
  while(fin.good())
  {
    if(tmpCnt % 1000 == 0)
      cout << ".";
    cout.flush();
    
    tmpCnt++;
    
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0)
      continue;
    
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue;
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    temp.name = course;
    temp.count = 1;
    
    if(head)
    {
      for(p = head, prev = 0; p; prev = p, p = p->next)
      {
        if(p->data.name == course)
        {
          p->data.count++;
          flag = 0;
          break;
        }
      }
      if(flag)
      {
        for(p = head, prev = 0; p; prev = p, p = p->next);
        Node* node = new Node;
        node->data = temp;
        node->next = 0;
        if (prev)
        {
          prev->next = node;
        }
        else
        {
          head->next = node;
        }
      }
    }
    else
    {
      Node* node = new Node;
      node->data = temp;
      node->next = 0;
      head = node;
    }
    
    flag = 1;
  }
  fin.close();
  
  cout << endl << endl;
  
  Node *q;
  for(p = head; p; p = p->next)
  {
    for(q = p->next; q; q = q->next)
    {
      if (p->data.name.compare(q->data.name) > 0)
        swap(p->data, q->data);
    }
  }
  
  for(p = head; p; p=p->next)
    cout << (p->data).name << ", " << (p->data).count << " classes" << endl;
  
  while(head)
  {
    p = head->next;
    delete head;
    head = p;
  }
  
  cout << endl << endl;
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  cout << "Elapsed Seconds: " << elapsedSeconds << endl;
}
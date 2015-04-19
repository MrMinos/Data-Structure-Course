// Lab 8c, Use A Stack
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstring>
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

  stack<char> mStack;
  stack<int> lStack;
  string userIn;
  ifstream fin;
  char continueQ = 'a';
  char errorCheck = 'z';
  int lineCnt = 0;

  cout << "Enter filename (H, CPP, JAVA, HTML, or JS), Q for exit:  ";
  getline(cin, userIn);
  if (userIn.size() == 1)continueQ = userIn[0];
  
  while(continueQ != 'Q')
  {     
    try 
    {
      fin.open((userIn.c_str()));
      if (!fin.good())
        throw  1;
    }
    catch (int n)
    {
      lineCnt = 0; errorCheck = '1';
      if (!mStack.empty())
      {
        for (int i = 0; i < mStack.size(); i++) mStack.pop();
      }
      if (!lStack.empty())
      {
        for (int i = 0; i < lStack.size(); i++) lStack.pop();
      }
      cout << endl << "I/O error" << endl << endl;
    }

    while (fin.good())
    {
      lineCnt++;

      string line;
      getline(fin, line);
      
      for(int i = 0; i < line.length(); i++)
      {
        if(line[i] == '(' || line[i] == '[' || line[i] == '{')
        {
          mStack.push(line[i]);
          lStack.push(lineCnt);
          
          continue;
        }
        
        if(line[i] == '*' && i > 0)
        {
          if(line[i-1] == '/')
          {
            mStack.push(line[i]);
            lStack.push(lineCnt);
          }
          
          continue;
        }
        
        if(line[i] == ']')
        {
          if(mStack.size() == 0)
          {
            errorCheck = 'B';
            mStack.push(line[i]);
            lStack.push(lineCnt);
            
            break;
          }
          
          if(mStack.top() == '[')
          {
            mStack.pop();
            lStack.pop();
          }
          else
          {
            errorCheck = 'b';
            mStack.push(line[i]);
            lStack.push(lineCnt);
            
            break;
          }
          
          continue;
        }
        
        if(line[i] == '}')
        {
          if(mStack.size() == 0)
          {
            errorCheck = 'C';
            mStack.push(line[i]);
            lStack.push(lineCnt);
            
            break;
          }
          if(mStack.top() == '{')
          {
            mStack.pop();
            lStack.pop();
          }
          else
          {
            errorCheck = 'c';
            mStack.push(line[i]);
            lStack.push(lineCnt);
            
            break;
          }
          
          continue;
        }
        
        if(line[i] == ')')
        {
          if(mStack.size() == 0)
          {
            errorCheck = 'P';
            mStack.push(line[i]);
            lStack.push(lineCnt);
            
            break;
          }
          
          if(mStack.top() == '(')
          {
            mStack.pop();
            lStack.pop();
          }
          else
          {
            errorCheck = 'p';
            mStack.push(line[i]);
            lStack.push(lineCnt);
            
            break;
          }
          
          continue;
        }
        
        if(line[i] == '/' && i > 0)
        {
          if(line[i-1] == '*')
          {
            if(mStack.size() == 0)
            {
              errorCheck = 'S';
              mStack.push(line[i]);
              lStack.push(lineCnt);
              
              break;
            }
            
            if(mStack.top() == '*')
            {
              mStack.pop();
              lStack.pop();
            }
            else
            {
              errorCheck = 's';
              mStack.push(line[i]);
              lStack.push(lineCnt);
              
              break;
            }
          }
        }
        
        if(errorCheck != 'z')
          break;
      }
      
      if(errorCheck != 'z')
        break;
    }
    
    fin.close();
    
    if(errorCheck != 'z')
    { 
      if(errorCheck == 'B')
      {
        cout << "  Line: " << lStack.top() << ": closing \']\' found without \'[\'" << " of " << userIn << endl;
      }
      else if(errorCheck == 'C')
      {
        cout << "  Line: " << lStack.top() << ": closing \'}\' found without \'{\'" << " of " << userIn << endl;
      }
      else if(errorCheck == 'P')
      {
        cout << "  Line: " << lStack.top() << ": closing \')\' found without \'(\'" << " of " << userIn << endl;
      }
      else if(errorCheck == 'S')
      {
        cout << "  Line: " << lStack.top() << ": closing \'*/\' found without \'/*\'" << " of " << userIn << endl;
      }
      else if(errorCheck == 'b')
      {
        mStack.pop();
        lStack.pop();
        
        cout << " Opening " << mStack.top() << " found on line " << lStack.top() << " of " << userIn << endl;
        cout << " (expected \'[\')" << endl;
      }
      else if(errorCheck == 'c')
      {
        mStack.pop();
        lStack.pop();
        
        cout << " Opening " << mStack.top() << " found on line " << lStack.top() << " of " << userIn << endl;
        cout << " But no closing \')\' found" << endl;
      }
      else if(errorCheck == 'p')
      {
        mStack.pop();
        lStack.pop();
        
        cout << " preceded by " << mStack.top() << " on line " << lStack.top() << " of " << userIn << endl;
        cout << " (expected \'(\')" << endl;
      }
      else if(errorCheck == 's')
      {
        cout << "  Line: " << lStack.top() << ": closing *" << mStack.top() << " of " << userIn << endl;
        mStack.pop();
        lStack.pop();
        
        cout << " preceded by " << mStack.top() << " on line " << lStack.top() << " of " << userIn << endl;
        cout << " (expected \'/*\')" << endl;
      }
      else if (errorCheck == '1');
      else cout << "  Errorcode: " << errorCheck << endl;
    }
    else if(mStack.size() > 0)
    {
      cout << "  Error: " << mStack.size() << " opening character remains on the stack of " << userIn << endl;
      cout << "  The first unmatched notation is : ";
      
      if(mStack.top() == '*')
        cout << "/";
      
      cout << mStack.top() << " on line " << lStack.top() << "." << endl;
    }
    else if (errorCheck == 'z') cout << "  Total " << lineCnt << " lines No mismatches found of " << userIn << endl;
    
    cout << "Enter Q to quit or enter filename to check other files: ";
    getline(cin, userIn);
    if (userIn.size() == 1) continueQ = userIn[0];
    cout << endl;

    if (!mStack.empty())
    {
      for (int i = 0; i < mStack.size(); i++) mStack.pop();
    }
    if (!lStack.empty())
    {
      for (int i = 0; i < lStack.size(); i++) lStack.pop();
    }
    lineCnt = 0; errorCheck = 'z';
    
    if(continueQ == 'q') continueQ = 'Q';
  }
}
// Lab 4a, Introduction To Dynamic Arrays
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include "ServerGroup.h"
#include "ServerGroup.h" // the header test

#include <iostream>
using namespace std;

#include <cassert>

int main() 
{
  cout << "Lab 4a, Introduction To Dynamic Arrays"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 


  ServerGroup test;
  test = ServerGroup(4);

  if(test.serverFree()) test.useServer(10);
  else cout << "Sorry come back later" << endl;
  cout << "serverFree and spServerFree expected to return true" << endl;
  cout << "Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl << endl;
  assert(true == test.serverFree() && true == test.spServerFree());

  test.decServers();  test.decServers();  test.decServers();  test.decServers();

  if(test.serverFree()) test.useServer(4);
  else cout << "Sorry come back later" << endl;
  cout << "serverFree and spServerFree expected to return true" << endl;
  cout << "Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl << endl;
  assert(true == test.serverFree() && true == test.spServerFree());

  test.decServers();  test.decServers();

  for (int i = 1; i <= 5; i++)
  {
    if(test.serverFree()) test.useServer(i);
    else cout << "Sorry come back later" << endl;
    if(test.serverFree())
    {
      cout << "serverFree and spServerFree expected to return true" << endl;
      cout << "Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl << endl;
      assert(true == test.serverFree() && true == test.spServerFree());
    }
    else
    {
      cout << "serverFree expected to return false and spServerFree expected to return true" << endl;
      cout << "Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl << endl;
      assert(false == test.serverFree() && true == test.spServerFree());
    }
  }

  if(test.spServerFree()) test.usespServer(20);
  else cout << "Sorry, special server not available" << endl;
  cout << "serverFree and spServerFree should return false" << endl;
  cout << "Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl << endl;
  assert(false == test.serverFree() && false == test.spServerFree());

  test.decServers(); test.decServers(); test.decServers();

  if(test.spServerFree()) test.usespServer(10);
  else cout << "Sorry, special server not available" << endl;
  cout << "serverFree should return true and spServerFree should return false" << endl;
  cout << "Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl << endl;
  assert(true == test.serverFree() && false == test.spServerFree());

  test.decServers();

  test.decServers();test.decServers();test.decServers();test.decServers();test.decServers();
  test.decServers();test.decServers();test.decServers();test.decServers();test.decServers();

  test.decServers();test.decServers();test.decServers();test.decServers();test.decServers();
  test.decServers();test.decServers();test.decServers();test.decServers();test.decServers();

  cout << "serverFree and spServerFree should return true" << endl;
  cout << "Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl << endl;
  assert(true == test.serverFree() && true == test.spServerFree());

  //object copy test
  ServerGroup copy = test;
  cout << "test: Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl;
  cout << "copy: Actual value for serverFree " << copy.serverFree() << ", for spServerFree " << copy.spServerFree() << endl;
  assert(true == test.serverFree() && true == test.spServerFree());
  cout << "Object copy test passed!" << endl << endl;

  //object assignment test
  ServerGroup copy2; copy2 = test;
  cout << "test: Actual value for serverFree " << test.serverFree() << ", for spServerFree " << test.spServerFree() << endl;
  cout << "copy2: Actual value for serverFree " << copy2.serverFree() << ", for spServerFree " << copy2.spServerFree() << endl;
  assert(true == test.serverFree() && true == test.spServerFree());
  cout << "Object assignment test passed!" << endl << endl;
}

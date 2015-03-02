#include <iostream> 
using namespace std;

#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h" // Testing ifndef
struct SubjectCode
{
  int sectionCount;
  string section;
  string term;
  string name;
};

int main()
{
  Array<int> a;
  a[0]=100;
  assert(100==a[0]);
  assert(a.containsKey(1)==0);

  a[3]=100;

  a[7]=100;
    assert(a.containsKey(7)==1);
  assert(a.containsKey(6)==0);
  assert(a.containsKey(8)==0);
  a[8]=100;
  assert(a[8]==100);

  Array<int> copy = a;
  Array<int> copy2; copy2 = a;

  Array<SubjectCode> b;
  b[5].sectionCount = 0;
  int temp = b[1].sectionCount;
  cout << temp;
}
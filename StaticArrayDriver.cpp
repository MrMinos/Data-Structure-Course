#include <iostream> 
using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h" // Testing ifndef

int main()
{
  Array<int, 10> a;
  a[0]=100;
  assert(100==a[0]);

  Array<int, 10> copy = a;
  Array<int, 10> copy2; copy2 = a;
}
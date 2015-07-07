// Lab 14a, Write A Sortable Array Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <algorithm>
#include <stack>

using namespace std;

#ifndef SortableArray_h
#define SortableArray_h

template <class DataType, int CAPACITY>
class SortableArray
{
  DataType data[CAPACITY], dummy;
  bool inUse[CAPACITY];

public:
  SortableArray(){for(int i = 0; i < CAPACITY; i++) inUse[i] = false;}
  DataType operator[](int) const;
  DataType& operator[](int);
  int capacity()const{return CAPACITY;}
  int size()const;
  int lsearch(const DataType&) const;
  bool containskey(int i) const{return (i < 0 || i >= CAPACITY)?false:inUse[i];}
  void deletekey(int);
  void sort(int);
  int bsearch(int,const DataType&) const;
};

template <class DataType, int CAPACITY>
DataType& SortableArray<DataType, CAPACITY>::operator[](int i)
{
  if(i < 0 || i >= CAPACITY)
    return dummy;
  
  inUse[i] = true;
  
  return data[i];
}

template <class DataType, int CAPACITY>
DataType SortableArray<DataType, CAPACITY>::operator[](int i) const
{
  if(i < 0 || i >= CAPACITY || inUse[i] == false)
    return dummy;
  
  return data[i];
}

template <class DataType, int CAPACITY>
int SortableArray<DataType, CAPACITY>::size() const
{
  int count=0;
  for(int i = 0; i < CAPACITY; i++)
  {
    if(inUse[i] == true)
      count++;
  }
  return count;
}

template <class DataType, int CAPACITY>
int SortableArray<DataType, CAPACITY>::lsearch(const DataType& value) const
{
  for(int i = 0; i < CAPACITY; i++)
  {
    if(inUse[i] == true && data[i] == value)
      return i;
  }
  
  return -1;
}

template <class DataType, int CAPACITY>
void SortableArray<DataType, CAPACITY>::deletekey(int i)
{
  if(i < 0 || i >= CAPACITY)
    return;
  inUse[i] = false;
}

template <class DataType, int CAPACITY>
void SortableArray<DataType, CAPACITY>::sort(int range)
{
  stack<pair<int, int> > s;
  pair<int, int> p;
  p.first = 0;
  p.second = range;
  s.push(p);
  
  while(!s.empty())
  {
    int head = s.top().first;
    int back = s.top().second;
    s.pop();
    if(head >= back - 1)
      continue;
    int pivot = (head + back - 1) / 2;
    int left = head;
    int right = back - 1;
    
    while(1)
    {
      while(left < pivot)
      {
        if(data[pivot] < data[left])
          break;
        left+=1;
      }
      while(pivot < right)
      {
        if(data[right] < data[pivot])
          break;
        right-=1;
      }
      if(left == right)
      {
        pair<int, int> p;
        p.first = head;
        p.second = pivot;
        s.push(p);
        p.first = pivot + 1;
        p.second = back;
        s.push(p);
        
        break;
      }
      else if (left == pivot)
      {
        swap(data[pivot], data[right]);
        pivot = right;
        left+=1;
      }
      else if (pivot == right)
      {
        swap(data[pivot], data[left]);
        pivot = left;
        right-=1;
      }
      else
      {
        swap(data[left], data[right]);
        left+=1;
        right-=1;
      }
    }
  }
}

template <class DataType, int CAPACITY>
int SortableArray<DataType, CAPACITY>::bsearch(int range, const DataType& target) const
{
  int start = 0;
  int end;
  
  if(range > size())
    range = size();
  
  end = range - 1;
  
  while(start != end)
  {
    int middle = (start + end) / 2;
    
    if(data[middle] == target)
    {
      return middle;
    }
    else if(data[middle] > target)
    {
      if(middle == start)
        break;
      else
      {
        end = middle - 1;
      }
    }
    else
    {
      if(middle == end)
        break;
      else
        start = middle + 1;
    }
  }
  return -1;
}

#endif

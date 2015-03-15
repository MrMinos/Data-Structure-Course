// Lab 5a, Write A Static Array Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef StaticArray_h
#define StaticArray_h

template <class DataType, int CAPACITY>
class Array
{
  DataType dummy;
  DataType data[CAPACITY];
  bool inUse[CAPACITY];

public:
  Array(){for (int i = 0; i < CAPACITY; i++) inUse[i]=false;}
  DataType& operator[](int);
  int capacity() const {return CAPACITY;}
  int size() const;
  int lsearch(const DataType&) const;
  bool containsKey(int i) const {return (i < 0 || i >= CAPACITY)?dummy:inUse[i];}
  void deleteKey(int i) {(i < 0 || i >= CAPACITY)?dummy:inUse[i]=false;}
};
template <class DataType, int CAPACITY>
DataType& Array<DataType, CAPACITY>::operator[](int i)
{
  if (!(i < 0 || i >= CAPACITY)) inUse[i]=true;
  return ((i < 0 || i >= CAPACITY)?dummy:data[i]);
}
template <class DataType, int CAPACITY>
int Array<DataType, CAPACITY>::size() const
{
  int count = 0;
  for(int i = 0; i < CAPACITY; i++) count += ((inUse[i]==true)?1:0);
  return count;
}

template <class DataType, int CAPACITY>
int Array<DataType, CAPACITY>::lsearch(const DataType& d) const
{
  int result = -1;
  for(int i = 0; i < size(); i++)
  {
    if(data[i] == d)
    {
      result = i;
      break;
    }
  }
  return result;
}
#endif
// Lab 12a, Write And Test A Priority Queue Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef PriorityQueue_h
#define PriorityQueue_h

#ifndef DynamicArray_h
#define DynamicArray_h

#include <iostream>

template <class DataType>
class Array
{
  DataType* dummy = NULL;
  DataType* data = NULL;
  int CAPACITY;
  int inUseIndex;
  static const int INITIAL_CAPACITY = 2;
  void changeCapacity(int);

public:
  Array();
  Array(int);
  ~Array() {delete [] data; delete [] dummy;}
  Array(const Array<DataType>&);
  DataType& operator[](int);
  DataType& operator[](int) const;
  Array& operator=(const Array<DataType>&);
  int capacity() const {return CAPACITY;}
};

template <class DataType>
Array<DataType>::Array()
{
  CAPACITY = INITIAL_CAPACITY;
  data = new DataType[CAPACITY];
  dummy = new DataType[1];
  inUseIndex = -1;
}

template <class DataType>
Array<DataType>::Array(int big)
{
  CAPACITY = big;
  data = new DataType[CAPACITY];
  dummy = new DataType[1];
  inUseIndex = -1;
}

template <class DataType>
DataType& Array<DataType>::operator[](int i)
{
  if(i >= CAPACITY)changeCapacity(2 * i);
  if(!(i < 0 || i >= CAPACITY))
  {
    if(i > inUseIndex) inUseIndex = i;
    return data[i];
  }
  else return dummy[0];
}

template <class DataType>
DataType& Array<DataType>::operator[](int i) const
{
  if(!(i < 0 || i >= CAPACITY))
  {
    return data[i];
  }
  else return dummy[0];
}

template <class DataType>
void Array<DataType>::changeCapacity(int newCAPACITY)
{
  DataType* temp = new DataType[newCAPACITY];
  for (int j = 0; j < CAPACITY; j++)
    temp[j] = data[j];
  delete [] data; 
  data = temp; 
  temp = NULL;
  CAPACITY = newCAPACITY;
}

template <class DataType>
Array<DataType>::Array(const Array<DataType>& a)
{
  CAPACITY = a.CAPACITY;
  data = new DataType[CAPACITY];
  for (int i = 0; i < CAPACITY; i++) data[i] = a.data[i];
}

template <class DataType>
Array<DataType>& Array<DataType>::operator=(const Array<DataType>& a)
{
  if (this == &a) return *this;

  CAPACITY = a.CAPACITY;
  delete [] data;
  data = new DataType[CAPACITY];
  for (int i = 0; i < CAPACITY; i++) data[i] = a.data[i];

  return *this;
}
#endif

template<class DataType>
class PriorityQueue
{
  int usedIndex, parentIndex, temp, size_var;
  Array<DataType> pq;
  DataType a;
public:
  PriorityQueue() {size_var = 0;}
  PriorityQueue(int big) {size_var = 0; for (int n = 0; n < big; n++, pq[n]);}
  void enqueue(const DataType&);
  DataType top() const {return pq[0];}
  DataType dequeue();
  bool empty() const {return (size_var == 0) ? true : false;}
  void clear() {size_var = 0;}
  int size() const {return size_var;}
};

template <class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& input)
{
  usedIndex = size_var;
  pq[usedIndex] = input;
  while (true)
  {
    parentIndex = (usedIndex + 1)/2 - 1;
    if (parentIndex < 0) break;
    if (pq[parentIndex] >= pq[usedIndex]) break;
    a = pq[parentIndex];
    pq[parentIndex] = pq[usedIndex];
    pq[usedIndex] = a;
    usedIndex = parentIndex;
  }
  size_var++;
}

template <class DataType>
DataType PriorityQueue<DataType>::dequeue()
{
  DataType b; 
  if (size_var != 0) b = pq[0];
  else return a;
  usedIndex = 0;
  while(true)
  {
    if (2 * usedIndex + 1 >= size_var) break;
    else if ((2 * usedIndex + 1 == size_var -1) || (pq[2 * usedIndex + 1] >= pq[2 * usedIndex + 2]))
    {
      pq[usedIndex] = pq[2 * usedIndex + 1];
      usedIndex = 2 * usedIndex + 1;
    }
    else
    {
      pq[usedIndex] = pq[2 * usedIndex + 2];
      usedIndex = 2 * usedIndex + 2;
    }
  }
  size_var--;
  pq[usedIndex] = pq[size_var];
  while (true)
  {
    parentIndex = (usedIndex + 1)/2 - 1;
    if (parentIndex < 0) break;
    if (pq[parentIndex] >= pq[usedIndex]) break;
    a = pq[parentIndex];
    pq[parentIndex] = pq[usedIndex];
    pq[usedIndex] = a;
    usedIndex = parentIndex;
  }
  return b;
}
#endif
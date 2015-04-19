// Lab 12a, Write And Test A Priority Queue Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef PriorityQueue_h
#define PriorityQueue_h

#ifndef DynamicArray_h
#define DynamicArray_h

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
  ~Array() {delete [] data; delete [] dummy;}
  Array(const Array<DataType>&);
  DataType& operator[](int);
  DataType& operator[](int) const;
  Array& operator=(const Array<DataType>&);
  int capacity() const {return CAPACITY;}
  int size() const {return (inUseIndex >= 0)(inUseIndex + 1):0;}
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
  int usedIndex;
  Array<DataType> pq;
  void swap();
public:
  PriorityQueue(int=2);
  void enqueue(const DataType&);
  DataType top() const;
  DataType dequeue();
  bool empty() const;
  void clear();
  int size() const;
};

template <class DataType>
PriorityQueue<DataType>::PriorityQueue()
{
  usedIndex = 0;
}

template <class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& input)
{
  pq[usedIndex] = input;
  for (int i = 0; i < usedIndex; i++)
  {
    parentIndex = (usedIndex + 1)/2 - 1;
    if (parentIndex < 0) break;
    if (pq[parentIndex] >= pq[usedIndex]) swap();
  }
}
#endif
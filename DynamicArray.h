// Lab 6a, Write A Dynamic Array Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef DynamicArray_h
#define DynamicArray_h

template <class DataType>
class Array
{
  DataType* dummy = NULL;
  DataType* data = NULL;
  bool* inUse = NULL;
  int CAPACITY;
  int inUseIndex;
  static const int INITIAL_CAPACITY = 2;
  void changeCapacity(int);

public:
  Array();
  ~Array() {delete [] data; delete [] inUse; delete [] dummy;}
  Array(const Array<DataType>&);
  DataType& operator[](int);
  DataType& operator[](int) const;
  Array& operator=(const Array<DataType>&);
  int capacity() const {return CAPACITY;}
  int size() const {return inUseIndex + 1;}
  int lsearch(const DataType&);
  bool containsKey(int i) const {return (i < 0 || i >= CAPACITY)?false:inUse[i];}
  void deleteKey(int i) {if(!(i < 0 || i >= CAPACITY)) inUse[i]=false;}
};

template <class DataType>
Array<DataType>::Array()
{
  CAPACITY = INITIAL_CAPACITY;
  data = new DataType[CAPACITY];
  dummy = new DataType[1];
  inUse = new bool[CAPACITY];
  for (int i = 0; i < CAPACITY; i++)
    inUse[i]=false;
  inUseIndex = 0;
}

template <class DataType>
DataType& Array<DataType>::operator[](int i)
{
  if(i >= CAPACITY)changeCapacity(2 * i);
  if(!(i < 0 || i >= CAPACITY))
  {
    if(i > inUseIndex) inUseIndex = i;
    inUse[i] = true;
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
  bool* temp2 = new bool[newCAPACITY];
  for (int j = 0; j < newCAPACITY; j++)
    temp2[j]=false;
  for (int j = 0; j < CAPACITY; j++)
  {
    temp[j] = data[j];
    temp2[j] = inUse[j];
  }
  delete [] data; 
  delete[] inUse;
  data = temp; 
  inUse = temp2;
  temp = NULL;
  temp2 = NULL;
  CAPACITY = newCAPACITY;
}

template <class DataType>
int Array<DataType>::lsearch(const DataType& d)
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

template <class DataType>
Array<DataType>::Array(const Array<DataType>& a)
{
  CAPACITY = a.CAPACITY;
  data = new DataType[CAPACITY];
  inUse = new bool[CAPACITY];
  for (int i = 0; i < CAPACITY; i++) data[i] = a.data[i];
  for (int i = 0; i < CAPACITY; i++) inUse[i] = a.inUse[i];
}

template <class DataType>
Array<DataType>& Array<DataType>::operator=(const Array<DataType>& a)
{
  if (this == &a) return *this;

  CAPACITY = a.CAPACITY;
  delete [] data;
  data = new DataType[CAPACITY];
  for (int i = 0; i < CAPACITY; i++) data[i] = a.data[i];
  
  delete [] inUse;
  inUse = new bool[CAPACITY]();
  for (int i = 0; i < CAPACITY; i++) inUse[i] = a.inUse[i];

  return *this;
}
#endif
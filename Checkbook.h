// Lab 4b, Introduction To Dynamic Array Doubling And Deallocation
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef Checkbook_h
#define Checkbook_h

template <class DataType>
class Checkbook
{
  DataType* data;
  int* track;
  DataType bal;
  int size = 2, track_num = 0;
  void doubleArray();

public:
  Checkbook(const DataType&);
  DataType* getChecks() const;
  DataType getBalance() const {return bal;}
  void writeChecks(const DataType&);
  int getNumCheckWritten() const {return track_num;}
  void makeDeposit(const DataType& deposit){bal += deposit;}
};

template <class DataType>
Checkbook<DataType>::Checkbook(const DataType& initialBal)
{
  data = new DataType[size];
  track = new int[size]();
  bal = initialBal;
}
template <class DataType>
DataType* Checkbook<DataType>::getChecks() const
{
  DataType* dumb = new DataType[size];
  for (int i = 0; i < size; i++)
    dumb [i] = data [i];
  return dumb; // client must free the returned array after use
}
template <class DataType>
void Checkbook<DataType>::writeChecks(const DataType& input)
{
  if(track[size - 1])  doubleArray();
  bal -= input;
  data[track_num] = input;
  track[track_num] = 1;
  track_num++;
}
template <class DataType>
void Checkbook<DataType>::doubleArray()
{
  size *= 2;
  DataType* temp = new DataType[size];
  for (int i = 0; i < size/2; i++)
    temp[i] = data[i];
  delete [] data;
  data = temp;

  int* temp2 = new int[size]();
  for (int i = 0; i < size/2; i++)
  	temp2[i] = track[i];
  delete [] track;
  track = temp2;
}
#endif
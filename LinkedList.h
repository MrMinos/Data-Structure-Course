// Lab 10a, Write And Test The ListedList Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#include <cassert>

#ifndef LinkedList_h
#define LinkedList_h

template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};

template <class DataType>
class LinkedList
{
  int size;
  int currentIndex;
  void assertSize() const {assert(currentIndex < size);}
  Node<DataType>* front;
  Node<DataType>* current;

public:
  LinkedList() : front(0), current(0) {currentIndex = -1; size = 0;}
  ~LinkedList();
  LinkedList(const LinkedList<DataType>& lCopy);
  LinkedList<DataType>& operator=(const LinkedList<DataType>& lCopy);
  void insert(const DataType& parameter);
  void makeEmpty();
  bool remove(DataType& parameter);
  bool replace(const DataType& parameter);
  bool find (const DataType& parameter);
  bool first (DataType& parameter);
  bool getNext (DataType& parameter);
  bool retrieve (DataType& parameter);
  bool isEmpty() const {return front == 0;}
  int length() const {return size;}
  DataType& operator[] (int index);
  int currentIndexi(){return currentIndex;}
};

template <class DataType>
LinkedList<DataType>::~LinkedList()
{
  Node<DataType>* p;
  
  while (front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}


template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& lCopy) : front(0), current(0)
{
  size = lCopy.size;
  currentIndex = lCopy.currentIndex;
  
  Node<DataType>* p;
  Node<DataType>* end = 0;
  
  for(p = lCopy.front; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    
    if (end)
      end->next = node;
    else
      front = node;
    
    end = node;
    
    if(p == lCopy.current)
      current = node;
  }
}


template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& lCopy)
{
  if(this != &lCopy)
  {
    size = lCopy.size;
    currentIndex = lCopy.currentIndex;
    current = 0;
    
    Node<DataType>* p;
    Node<DataType>* end = 0;
    
    while(front)
    {
      p = front->next;
      delete front;
      front = p;
    }
    
    for(p = lCopy.front; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      
      if(end)
        end->next = node;
      else
        front = node;
      
      end = node;
      
      if(p == lCopy.current)
        current = node;
    }
  }
  
  return *this;
}


template <class DataType>
void LinkedList<DataType>::insert(const DataType& parameter)
{
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = front;
  front = node;
  current = front;
  currentIndex = 0;
  size++;
}


template <class DataType>
void LinkedList<DataType>::makeEmpty()
{
  currentIndex = -1;
  size = 0;
  
  while(front)
  {
    current = front->next;
    delete front;
    front = current;
  }
}

template <class DataType>
bool LinkedList<DataType>::remove(DataType& parameter)
{
  Node<DataType>* p;
  Node<DataType>* prev;
  for(prev = 0, p = front; p; prev = p, p = p->next)
  {
    if(p->data == parameter)
      break;
  }
  
  if(!p)
    return false;
  
  if(prev)
    prev->next = p->next;
  else
    front = p->next;
  
  if(p == current)
    current = current->next;
  parameter = p->data;
  delete p;
  size--;
  
  return true;
}

template <class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter)
{
  if (!current)
    return false;
  current->data = parameter;
  
  return true;
}


template <class DataType>
bool LinkedList<DataType>::find(const DataType& parameter)
{
  Node<DataType>* reCurrent = current;
  int reIndex = currentIndex;
  
  DataType temp;
  if(first(temp))
  {
    do
    {
      if(parameter == temp)
        return true;
    }
    while (getNext(temp));
  }
  
  current = reCurrent;
  currentIndex = reIndex;
  
  return false;
}


template <class DataType>
bool LinkedList<DataType>::first(DataType& parameter)
{
  if(!front)
    return false;
  parameter = front->data;
  current = front;
  currentIndex = 0;
  return true;
}


template <class DataType>
bool LinkedList<DataType>::getNext(DataType& parameter)
{
  if(!current)
    return false;
  if(!current->next)
    return false;
  
  current = current->next;
  currentIndex++;
  
  parameter = current->data;
  
  return true;
}


template <class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter)
{
  if (!find(parameter))
    return false;
  parameter = current->data;
  return true;
}


template <class DataType>
DataType& LinkedList<DataType>::operator[] (int index)
{
  int element = index;
  Node<DataType>* p;
  
  if(element < 0 || element >= size)
  {
    Node<DataType>* dummy = new Node<DataType>;
    p = dummy;
    delete dummy;
    throw "in operator[] - index out of bounds.";
    return p->data;
  }
  
  if(element >= currentIndex)
  {
    element -= currentIndex;
    
    for(p = current; p; p = p->next)
    {
      if(element == 0)
      {
        current = p;
        currentIndex = index;
        return p->data;
      }
      element--;
    }
  }
  
  for(p = front; p; p = p->next)
  {
    if(element == 0)
    {
      current = p;
      currentIndex = index;
      return p->data;
    }
    element--;
  }
  
  throw "Error in operator[] - reached end of function.";
}

#endif
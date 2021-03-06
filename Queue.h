// Lab 8b, Write And Test A Queue Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef Queue_h
#define Queue_h

template <class DataType>
struct Node
{
  Node* prev = NULL;
  DataType data;
  Node* next = NULL;
};

template <class DataType>
class Queue
{
  Node<DataType>* root = NULL;
  Node<DataType>* step = NULL;
  Node<DataType>* last = NULL;
  DataType temp;
  DataType dummy;

  public:
  Queue();
  ~Queue();
  DataType pop();
  DataType peek(){return root->next->data;}
  void push(DataType);
  int size();
  bool empty(){return (size() == 0?true:false);}
  Queue(const Queue<DataType>& a);
  Queue<DataType>& operator=(const Queue<DataType>& a);
  void clear();
};

template <class DataType>
Queue<DataType>::Queue()
{
  root = new Node<DataType>;
  root->prev = NULL;
  root->next = NULL;
  step = root;
  last = root;
}

template <class DataType>
Queue<DataType>::~Queue()
{
  step = root;
  while (step != NULL)
  {
  	last = step->next;
  	delete step;
  	step = last;
  }
}

template <class DataType>
DataType Queue<DataType>::pop()
{
  if(size() > 1)
  {
    temp = root->next->data;
    step = root->next;
    root->next = root->next->next;
    delete step;
    root->next->prev = root;
    return temp;
  }
  else if(size() == 1)
  {
    temp = root->next->data;
    delete root->next;
    root->next = NULL;
    last = root;
    return temp;
  }
  else return dummy;
}

template <class DataType>
void Queue<DataType>::push(DataType datum)
{
  last->next = new Node<DataType>;
  step = last;
  last = last->next;
  last->prev = step;
  last->next = NULL;
  last->data = datum;
}

template <class DataType>
int Queue<DataType>::size()
{
  int size = 0;
  step = root->next;
  while (step != NULL)
  {
  	size++;
  	step = step->next;
  }
  return size;
}

template <class DataType>
Queue<DataType>::Queue(const Queue<DataType>& a)
{
  Node<DataType>* end = NULL;
  root = new Node<DataType>;
  for (step = a.root; step; step = step->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = step->data;
    node->next = NULL;
    node->prev = end;
    if (end) end->next = node;
    else root = node;
    end = node;
  }
  last = end;
}

template <class DataType>
Queue<DataType>& Queue<DataType>::operator=(const Queue<DataType>& a)
{
  if (this != &a)
  {
    Node<DataType>* end = NULL;

    while (root)
    {
      step = root->next;
      delete root;
      root = step;
    }
    root = new Node<DataType>;
    root->next = NULL;
    root->prev = NULL;
    for (step = a.root; step; step = step->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = step->data;
      node->next = NULL;
      node->prev = end;
      if (end) end->next = node;
      else root = node;
      end = node;
    }
    last = end;
  }
  return *this;
}

template <class DataType>
void Queue<DataType>::clear()
{
  if (step != root)
  {
    step = root->next;
    while (step)
    {
      delete step;
      step = step->next;
    }
    root->next = NULL;
    last = root;
    step = root;
  }
  else if(step == root)
  {
    root->next = NULL;
    last = root;
  }
}
#endif
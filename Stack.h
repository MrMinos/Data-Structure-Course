// Lab 8a, Write And Apply A Stack Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef Stack_h
#define Stack_h

template <class DataType>
struct Node
{
  Node* prev = NULL;
  DataType data;
  Node* next = NULL;
};

template <class DataType>
class Stack
{
  Node<DataType>* root = NULL;
  Node<DataType>* step = NULL;
  Node<DataType>* last = NULL;
  DataType temp, dummydata;

  public:
  Stack();
  ~Stack();
  DataType pop();
  DataType peek(){return last->data;}
  void push(DataType);
  int size();
  bool empty(){return (size() == 0?true:false);}
  Stack(const Stack<DataType>& a);
  Stack<DataType>& operator=(const Stack<DataType>& a);
  void clear();
};

template <class DataType>
Stack<DataType>::Stack()
{
  root = new Node<DataType>;
  root->prev = NULL;
  root->next = NULL;
  step = root;
  last = root;
}

template <class DataType>
Stack<DataType>::~Stack()
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
DataType Stack<DataType>::pop()
{
  if (last != root)
  {
  	temp = last->data;
    last = last->prev;
    delete last->next;
    last->next = NULL;
    return temp;
  }
  else return dummydata;
}

template <class DataType>
void Stack<DataType>::push(DataType datum)
{
  last->next = new Node<DataType>;
  step = last;
  last = last->next;
  last->prev = step;
  last->next = NULL;
  last->data = datum;
}

template <class DataType>
int Stack<DataType>::size()
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
Stack<DataType>::Stack(const Stack<DataType>& a)
{
  Node<DataType>* end = NULL;
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
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& a)
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
void Stack<DataType>::clear()
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
}

#endif
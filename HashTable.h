// Lab 11a, Write And Test The HashTable Class Template
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <algorithm>
#include <list>
#include <vector>

#ifndef HashTable_H
#define HashTable_H

template <class KEY, class VALUE, int CAPACITY>
class HashTable
{

  public:
  HashTable(int(*hc) (const KEY&)){hc = hc; size_v = 0;}
  void deleteKey(const KEY&);
  void clear(){for(int i=0;i<CAPACITY;i++)data[i].clear(); size_v=0;}
  int size()const {return size_v;}
  int capacity()const{return 0.8*CAPACITY;}
  bool containsKey(const KEY&)const;
  vector<KEY>keys()const;
  struct Node
  {
    KEY key;
    VALUE value;
    void operator=(const VALUE& v){value = v;}
    bool operator==(const Node& n) const {return key == n.key;} 
  };
  VALUE& operator[](const KEY&);
  VALUE operator[](const KEY&)const;

  private:
  int getWrappedIndex(const KEY&)const;
  list<Node> data[CAPACITY];
  int size_v;
  int(*hc)(const KEY&);
};

template<class KEY,class VALUE, int CAPACITY>
int HashTable<KEY,VALUE,CAPACITY>::getWrappedIndex(const KEY& param)const
{
  int wrappedIndex = hashCode(param) % CAPACITY;
  if (wrappedIndex < 0) wrappedIndex += CAPACITY;
  return wrappedIndex;
}

template<class KEY,class VALUE, int CAPACITY>
void HashTable<KEY,VALUE,CAPACITY>::deleteKey(const KEY& del)
{
  int wrappedIndex = getWrappedIndex(del);
  Node temp; 
  temp.key = del;
  typename list<Node>::iterator it=find(data[wrappedIndex].begin(), data[wrappedIndex].end(), temp); 
  it = find(data[wrappedIndex].begin(), data[wrappedIndex].end(), temp); 
  if (it != data[wrappedIndex].end())
  {
    data[wrappedIndex].erase(it);
    size_v--;
  }
} 

template<class KEY,class VALUE, int CAPACITY>
vector<KEY>HashTable<KEY,VALUE,CAPACITY>::keys() const
{
  vector<KEY> keys;
  typename list<Node>::const_iterator it;
  for(int i=0;i<CAPACITY;i++)
  {
    for(it=data[i].begin();it!=data[i].end();it++) keys.push_back(it->key);
  }
  return keys;
}

template<class KEY,class VALUE, int CAPACITY>
VALUE HashTable<KEY,VALUE,CAPACITY>::operator[](const KEY& getter)const
{
  int wrappedIndex = getWrappedIndex(getter);
  Node temp; 
  temp.key = getter;
  typename list<Node>::iterator it=find(data[wrappedIndex].begin(), data[wrappedIndex].end(), temp); 
  it = find(data[wrappedIndex].begin(), data[wrappedIndex].end(), temp); 
  if (it == data[wrappedIndex].end()) return it->value;
  return temp.value;
}

template<class KEY,class VALUE, int CAPACITY>
bool HashTable<KEY,VALUE,CAPACITY>::containsKey(const KEY& key)const
{
  int wrappedIndex=getWrappedIndex(key);
  Node node;
  node.key=key;
  typename list<Node>::const_iterator it=find(data[wrappedIndex].begin(),data[wrappedIndex].end(),node);
  if(it !=data[wrappedIndex].end())
    return true;
  else 
    return false;
}

template<class KEY,class VALUE, int CAPACITY>
VALUE& HashTable<KEY,VALUE,CAPACITY>::operator[](const KEY& set)
{	
  int wrappedIndex =getWrappedIndex(set);
  Node node;
  node.key=set;
  typename list<Node>::iterator it = find(data[wrappedIndex].begin(), data[wrappedIndex].end(), node);
  if(it==data[wrappedIndex].end())
  {
    data[wrappedIndex].push_back(node);
    size_v++;
    return data[wrappedIndex].back().value;
  }
  else return it->value; 
}
#endif
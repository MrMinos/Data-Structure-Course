// Lab 15a, Write Functions For BFS and DFS
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Vertex
{
  string name;  
  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
  queue<int> searchOrder;
  queue<int> toDoList;
  if (iOriginVertex < 0 || iOriginVertex >= database.size()) return searchOrder;
  
  for (int i = 0; i < database.size(); i++)
    database[i].isVisited = false;

  database[iOriginVertex].isVisited = true;
  searchOrder.push(iOriginVertex);
  toDoList.push(iOriginVertex);
  
  while (!toDoList.empty())
  {
    int t = toDoList.front();
    toDoList.pop();
    for (list<int>::iterator it = database[t].adjacentVertices.begin(); it != database[t].adjacentVertices.end(); it++)
    {
      if (database[*it].isVisited == false)
      {
        database[*it].isVisited = true;
        searchOrder.push(*it);
        toDoList.push(*it);
      }
    }
  }
  
  return searchOrder;
}

queue<int> doDepthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
  queue<int> searchOrder;
  stack<int> toDoList;
  
  for (int i = 0; i < database.size(); i++) database[i].isVisited = false;
  if (iOriginVertex < 0 || iOriginVertex >= database.size()) return searchOrder;
  
  toDoList.push(iOriginVertex);
  
  while (!toDoList.empty())
  {
    int t = toDoList.top();
    toDoList.pop();
    
    if (database[t].isVisited == false)
    {
      database[t].isVisited = true;
      searchOrder.push(t);
      
      for (list<int>::reverse_iterator r_it = database[t].adjacentVertices.rbegin(); r_it != database[t].adjacentVertices.rend(); ++r_it)
      {
        if (database[*r_it].isVisited == false)
          toDoList.push(*r_it);
      }
    }
  }
  
  return searchOrder;
}

int main()
{
  cout << "Lab 15a, Write Functions For BFS and DFS\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";
  
  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity;
    
    // read one edge
    getline(fin, fromCity);
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    
    getline(fin, toCity);
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator
    
    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;
    
    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;
    
    // store bi-directional edges
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";
  
  while (true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;
    
    // find the start city
    int i;
    for (i = 0; i < database.size(); i++)
      if (database[i].name == startCity)
        break;
    
    //  -- skip the next code blocks if no matching city is found
    if (i < database.size())
    {
      // BFS result
      cout << "BFS";
      queue<int> q = doBreadthFirstSearch(i, database);
      while(!q.empty())
      {
        cout  << '-'<< database[q.front()].name;
        q.pop();
      }
      cout << endl;
      
      cout << "DFS";
      q = doDepthFirstSearch(i, database);
      while(!q.empty())
      {
        cout  << '-'<< database[q.front()].name;
        q.pop();
      }
      
      cout << endl;;
    }
  }
}
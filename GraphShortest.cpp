// Lab 15b, Write A Function For Shortest Route
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
#include <utility>
using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;
  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it;
  queue<int> toDoList;
  
  for (int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }
  
  database[iStart].isVisited = true;
  toDoList.push(iStart);
  
  while (!toDoList.empty())
  {
    int t = toDoList.front();
    toDoList.pop();
    
    for (it = database[t].adjacentVertices.begin(); it != database[t].adjacentVertices.end(); it++)
    {
      if (database[it->first].isVisited == false)
      {
        database[it->first].isVisited = true;
        database[it->first].cost = (database[t].cost + 1);
        database[it->first].prev = t;
        toDoList.push(it->first);
      }
      
      if (it->first == iEnd)
      {
        while(!toDoList.empty()) toDoList.pop();
        break;
      }
    }
  }
  
  result.second = database[iEnd].cost;
  
  for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev) result.first.push(vertex);
  
  return result;
}

int main()
{
  cout << "Lab 15b, Write A Function For Shortest Route\n"; 
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
    string fromCity, toCity, cost;
    
    // read one edge
    getline(fin, fromCity);
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    
    getline(fin, toCity);
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    
    getline(fin, cost);
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
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";
  
  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;
    
    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;
    
    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;
    
    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;
    
    if (iFrom < database.size() && iTo < database.size())
    {
      cout << "Route";
      pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
      while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
      cout << "Total edges: " << result.second;  
      cout << endl;
    }
    else
    {
      cout << "Not enough cities are found in the database!" << endl;
    }
  }
}
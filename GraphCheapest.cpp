// Lab 15c, Write A Function For Cheapest Route
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

struct Container
{
  int vertex;
  int prev;
  double cost;
  
  bool operator<(const Container& v) const {return cost > v.cost;}
};

struct Vertex
{
  string name;
  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  list<pair<int, double> >::iterator it;
  
  for (int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }
  
  priority_queue<Container> toDoList;
  
  Container startVertex;
  startVertex.cost = 0;
  startVertex.prev = -1;
  startVertex.vertex = iStart;
  
  toDoList.push(startVertex);
  
  while (!toDoList.empty())
  {
    Container temp = toDoList.top();
    toDoList.pop();
    
    if (database[temp.vertex].isVisited == true) continue;
    
    database[temp.vertex].isVisited = true;
    database[temp.vertex].cost = temp.cost;
    database[temp.vertex].prev = temp.prev;
    
    if (temp.vertex == iEnd) break;
    
    for (it = database[temp.vertex].adjacentVertices.begin(); it != database[temp.vertex].adjacentVertices.end(); ++it)
    {
      int thisNeighborsIndex = it->first;
      double thisNeighborsCost = it->second;
      
      Container neighborsContainer;
      neighborsContainer.vertex = thisNeighborsIndex;
      neighborsContainer.cost = (temp.cost + thisNeighborsCost);
      neighborsContainer.prev = temp.vertex;
      
      toDoList.push(neighborsContainer);
    }
  }
  
  pair<stack<int>, double> result;
  stack<int> resultInts;
  int vertex = iEnd;
  
  result.second = database[iEnd].cost;
  
  while (vertex != -1)
  {
    resultInts.push(vertex);
    vertex = database[vertex].prev;
  }
  
  result.first = resultInts;
  return result;
}


int main()
{
  cout << "Lab 15c, Write A Function For Cheapest Route\n"; 
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
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator
    
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    
    // add vertices for new cities included in the edge
    int iToVertex = -1;
    int iFromVertex = -1;
    int i;
    
    for (i = 0; i < database.size(); i++) // seek "to" city
    {if (database[i].name == fromCity) break;} // end for()
    
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;
    
    for (i = 0; i < database.size(); i++) // seek "from" city
    {if (database[i].name == toCity) break;} // end for()
    
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
    string startCity;
    string endCity;
    int iStartCity = -1;
    int iEndCity = -1;
    
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;
    
    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, endCity);
    if (endCity.length() == 0) break;
    
    for (int i = 0; i < database.size(); i++)
    {
      if (startCity == database[i].name) iStartCity = i;
      if (endCity == database[i].name) iEndCity = i;
    }
    
    if (iStartCity >= 0 && iEndCity >= 0)
    {
      pair<stack<int>, double> result = getCheapestRoute(iStartCity, iEndCity, database);
      cout << "Total miles: " << result.second;
      while (!result.first.empty())
      {
        cout << "-" << database[result.first.top()].name;
        result.first.pop();
      }
    }
    else
    {
      cout << "ERROR: One or more cities not found in database..." << endl;
    }
    
    cout << endl << endl;
  }
}
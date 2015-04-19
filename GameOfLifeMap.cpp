// Lab 11b, Apply The STL map Template To The Classic Game Of Life Simulation
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <iostream>
#include <map>
using namespace std;

#include <cstdlib>

struct cell
{
  int row;
  int col;
  bool operator==(const cell& c) const {return row == c.row && col == c.col;}
  bool operator<(const cell& c)const{return(1000*row +col)<(1000*c.row+c.col);}
};

map<cell, int> grid, newGrid;
const int MINROW = -25;
const int MAXROW = 25;
const int MINCOL = -35;
const int MAXCOL = 35;
cell temp;

int counter(int row, int col)
{
  cell tempo;
  int count = 0;
  for (tempo.row = row - 1; tempo.row <= row + 1; tempo.row++)
    for (tempo.col = col - 1; tempo.col <= col + 1; tempo.col++)
      if (tempo.row != row || tempo.col != col)
        if (grid.find(tempo) != grid.end())
          ++count;
  return count;
}

void initialize()
{
  cout << "Sequence of pairs of coordinates, terminated with a pair of -1's" << endl;

  char buf[100];
  while (true)
  {
    cin >> buf; temp.row = atoi(buf);
    cin >> buf; temp.col = atoi(buf);
    if (temp.row == -1 && temp.col == -1) break;
    grid[temp] = 'X';
  }
  cin.ignore();
}

void print()
{
  cout << endl << "The Current Life Configuration" << endl;
  
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
      if (grid.find(temp) != grid.end())
        cout << "X";
      else
        cout << ' ';
    cout << endl;
  }
  cout << endl;
}

void update()
{
  newGrid.clear(); 
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
    {
      switch (counter(temp.row, temp.col))
      {
        case 2:
          if (grid.find(temp) != grid.end()) newGrid[temp] = 'X';
          break;
        case 3:
          newGrid[temp] = 'X';
          break;
      }
    }
  }
  grid = newGrid;    
}

int main()
{
  // print my name and this assignment's title 
  cout << "Lab 11b, Apply The STL map Template To The Classic Game Of Life Simulation\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  initialize();
  print();
  for (int i = 1; grid.size(); i++)
  {
    cout << "Generation " << i << ". Press ENTER to continue, or \'q\' to quit...\n";
    if (cin.get() == 'q') break;
    update();
    print();
  }
}
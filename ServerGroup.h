// Lab 4a, Introduction To Dynamic Arrays
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#ifndef ServerGroup_h
#define ServerGroup_h

class ServerGroup
{
  int* servers;
  int spServer, freeServer, size;

public:
  ServerGroup(){}
  ServerGroup(int);
  bool spServerFree() const {return (spServer == 0 ? true:false);}
  bool serverFree();
  void useServer(int);
  void usespServer(int avTransTime){spServer = avTransTime;}
  void decServers();
};
#endif
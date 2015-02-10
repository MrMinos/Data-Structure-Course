// Lab 4a, Introduction To Dynamic Arrays
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include "ServerGroup.h"

ServerGroup::ServerGroup(int n)
{
  spServer = 0;
  size = n;
  servers = new int[size];
  for (int i = 0; i < size; i++) servers[i] = 0;
}

bool ServerGroup::serverFree()
{
  for(int i = 0; i<size; i++)
  {
  	if(servers[i] == 0)
  	{
  	  freeServer = i;
  	  return true;
  	}
  }
  return false;
}

void ServerGroup::useServer(int avTransTime)
{
  servers[freeServer] = avTransTime;
}

void ServerGroup::decServers()
{
  for(int i = 0; i < size; i++)
  {
  	if(servers[i]!=0)  servers[i]-=1;
  }
  if(!spServerFree()) spServer-=1;
}
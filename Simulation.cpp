// Lab 13, Write A Customer Service Simulation
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#include <cmath>
#include <cstdlib>

struct Customer
{
  int arrivalTime, serviceTime, completionTime;
  char customerID;
};

struct Service
{
  int serverNumber, clockTimeToEnd;
  bool operator<(const Service&) const;
};

bool Service::operator<(const Service& a) const
{
  return (bool)(clockTimeToEnd > a.clockTimeToEnd); //yes, it is backwards
}

int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX; 
    (randomValue -= probOfnRequests) > 0.0; 
    probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}

int getRandomNumber(int max, int min)
{
  int num = rand() % (max - min);
  return num + min;
}

int main()
{
  srand(time(0));
  // print my name and this assignment's title 
  cout << "Lab 13, Write A Customer Service Simulation\n"; 
  cout << "Programmer: Minos Park\n"; 
  cout << "Editor(s) used: Sublime Text 2\n"; 
  cout << "Compiler(s) used: G++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  int charCount = 0, counter, avgArrivalTime, avgCompletionTime, serviceTimeInterval, turnedAwayCustomers = 0, numberOfServiceRequests, internalClock, numberOfServers, maxLengthOfWaitQueue, minServiceTimeInterval, maxServiceTimeInterval, clockNewArrivalTimeStop;
  double avgArrivalRate;
  Service tempService;
  Customer tempCustomer, dummy;
  ifstream fin;
  string line;

  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";

  getline(fin, line);
  numberOfServers = stoi(line);
  cout << numberOfServers << endl;
  getline(fin, line);
  avgArrivalRate = stod(line);
  cout << avgArrivalRate << endl;
  getline(fin, line);
  maxLengthOfWaitQueue = stoi(line);
  cout << maxLengthOfWaitQueue << endl;
  getline(fin, line);
  minServiceTimeInterval = stoi(line);
  cout << minServiceTimeInterval << endl;
  getline(fin, line);
  maxServiceTimeInterval = stoi(line);
  cout << maxServiceTimeInterval << endl;
  getline(fin, line);
  clockNewArrivalTimeStop = stoi(line);
  cout << clockNewArrivalTimeStop << endl;
  fin.close();

  queue<Customer> waitQueue, tempQueue, serviceCompleted;
  priority_queue<Service> serviceEvents;
  vector<Customer> serverArray(numberOfServers);
  vector<bool> serverArrayInUse(numberOfServers);
  dummy.customerID = ' ';
  for (int i = 0; i < numberOfServers; i++) serverArrayInUse[i]=false;

  for (int t = 0;; t++)
  {
    while(!serviceEvents.empty() && serviceEvents.top().clockTimeToEnd <= t)
    {
      tempService = serviceEvents.top();
      serviceEvents.pop();
      serverArray[tempService.serverNumber].completionTime = t;
      serviceCompleted.push(serverArray[tempService.serverNumber]);
      serverArray[tempService.serverNumber] = dummy;
      serverArrayInUse[tempService.serverNumber] = false;
    }
    if(t < clockNewArrivalTimeStop)
    {
      numberOfServiceRequests = getRandomNumberOfServiceRequests(avgArrivalRate);
      for (int i = 0; i < numberOfServiceRequests; i++)
      {
        if (waitQueue.size() >= maxLengthOfWaitQueue)
        {
          turnedAwayCustomers++;
          break;
        }
        else
        {
          tempCustomer.arrivalTime = t;
          tempCustomer.customerID = (char)('A' + (charCount++ % 26));
          waitQueue.push(tempCustomer);
        }
      }
    }
    for (int i = 0; i < numberOfServers; i++)
    {
      if (serverArrayInUse[i]==false && waitQueue.size() > 0)
      {
        serverArray[i] = waitQueue.front();
        waitQueue.pop();
        serverArray[i].serviceTime = t;
        serviceTimeInterval = getRandomNumber(maxServiceTimeInterval, minServiceTimeInterval); 
        serverArrayInUse[i] = true;
        tempService.serverNumber = i;
        tempService.clockTimeToEnd = t + serviceTimeInterval;
        serviceEvents.push(tempService);
      }
    }
// Priority queue order

    cout << ">>> Current Time: " << t << " <<<" << endl;
    cout << "------------------------------------" << endl;
    cout << "line    now serving    wait queue   " << endl;
    cout << "----    -----------    ----------   " << endl;
    cout << " 0          " << serverArray[0].customerID << "          ";
    tempQueue = waitQueue;
    for (int i = 0; i < waitQueue.size(); i++)
    {
      cout << tempQueue.front().customerID << " ";
      tempQueue.pop();
    }
    cout << endl;
    for (int i = 1; i < numberOfServers; i++)
    {
      cout << " " << i << "          " << serverArray[i].customerID << endl;
    }
    cout << "------------------------------------" << endl;
    if (t > 0)
    {
      tempQueue = serviceCompleted;
      avgArrivalTime = 0; avgCompletionTime = 0; counter = 0;
      for (int i = 0; i < serviceCompleted.size(); i++)
      {
        tempCustomer = tempQueue.front();
        avgArrivalTime += tempCustomer.arrivalTime;
        avgCompletionTime += tempCustomer.completionTime;
        tempQueue.pop();
        counter++;
      }
      cout << "Avg time: " << ((double)(avgCompletionTime - avgArrivalTime) / (double)counter) << ". Turned away per minute: " << (double) turnedAwayCustomers / (double) t << endl;
    }
    cout << "Press ENTER to continue, X-ENTER to exit..." << endl;
    if (cin.get() == 'X') break;
  }
}
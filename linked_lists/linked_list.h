#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node(int);
};

class LinkedList{
private:
  Node *m_head;
public:
  LinkedList();
  void AddNode(int);
  void RemoveDups();
  void Print();
  int KthToLast(int);
  void BuildFromArgs(int, char **);
  void DeleteMiddleNode(int);
  void Partition(int);
  LinkedList *Add(LinkedList *);
};

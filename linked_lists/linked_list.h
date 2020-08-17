#include<iostream>
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
  int KthToLast();
};

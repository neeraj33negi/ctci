#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node(int);
};

class LinkedList{
public:
  Node *m_head;
  LinkedList();
  LinkedList(LinkedList *);
  void AddNode(int);
  void AddNodeLast(int);
  void RemoveDups();
  void Print();
  int KthToLast(int);
  void BuildFromArgs(int, char **);
  void DeleteMiddleNode(int);
  void Partition(int);
  LinkedList *Add(LinkedList *);
  bool IsPalindrome();
  Node *Intersection(LinkedList *);
  Node *DetectLoop();
  Node *LastNode();
  LinkedList *Merge(LinkedList *);
  void SwapPairs();
  void RotateList(int);
  void ReverseKGroup(int);
};


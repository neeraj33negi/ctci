#include "linked_list.h"

Node::Node(int data){
  this->data = data;
  this->next = NULL;
}

LinkedList::LinkedList(){
  m_head = NULL;
}

void LinkedList::AddNode(int data){
  Node *newNode = new Node(data);
  newNode->next = m_head;
  m_head = newNode;
}

void LinkedList::Print(){
  Node *temp = m_head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << "\n";
}

void LinkedList::RemoveDups(){
  unordered_map<int, bool> visitedMap;
  Node *previous = NULL;
  Node *currentNode = m_head;
  while(currentNode){
    if(visitedMap.find(currentNode->data) == visitedMap.end()){
      visitedMap[currentNode->data] = true;
      previous = currentNode;
      currentNode = currentNode->next;
    } else {
      previous->next = currentNode->next;
      delete(currentNode);
      currentNode = previous->next;
    }
  }
}

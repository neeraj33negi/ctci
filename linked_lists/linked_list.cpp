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

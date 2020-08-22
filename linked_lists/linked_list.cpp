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

void LinkedList::BuildFromArgs(int count, char **args){
  int i = count;
  while(--i >= 1){
    this->AddNode( atoi(args[i]) );
  }
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

int LinkedList::KthToLast(int k){
  Node *reference = m_head;
  Node *required = m_head;
  int count = k;
  while(count-- && reference){
    reference = reference->next;
  }
  if(!reference) return -1;
  while(reference){
    reference = reference->next;
    required = required->next;
  }
  return required->data;
}

// assuming k is node from the first to delete
void LinkedList::DeleteMiddleNode(int k){
  Node *current = m_head;
  while(--k && current){
    current = current->next;
  }
  if(!current || !current->next || current == m_head) return;
  Node *toDelete = current->next;
  current->data = toDelete->data;
  current->next = toDelete->next;
  delete(toDelete);
}

void LinkedList::Partition(int pivot){
  Node *first = new Node(-1), *second = new Node(-1), *current = m_head;
  Node *refFirst = first, *refSecond = second;
  while(current){
    if(current->data < pivot){
      first->next = current;
      first = current;
    }else{
      second->next = current;
      second = current;
    }
    current = current->next;
  }
  second->next = NULL;
  first->next = refSecond->next;
  m_head = refFirst->next;
}

LinkedList *LinkedList::Add(LinkedList *list2){
  LinkedList *newList = new LinkedList();
  Node *newListHead = NULL, *ptr1 = this->m_head, *ptr2 = list2->m_head, *previous = NULL;
  int rem = 0, currentSum;
  while(ptr1 && ptr2){
    currentSum = ptr1->data + ptr2->data + rem;
    if(currentSum >= 10){
      rem = 1;
      currentSum %= 10;
    }else{
      rem = 0;
    }
    Node *newNode = new Node(currentSum);
    if(previous){
      previous->next = newNode;
    }else{
      newListHead = newNode;
    }
    previous = newNode;
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  while(ptr1){
    currentSum = ptr1->data + rem;
    if(currentSum >= 10){
      rem = 1;
      currentSum %= 10;
    }else{
      rem = 0;
    }
    Node *newNode = new Node(currentSum);
    if(previous){
      previous->next = newNode;
    }else{
      newListHead = newNode;
    }
    previous = newNode;
    ptr1 = ptr1->next;
  }

  while(ptr2){
    currentSum = ptr2->data + rem;
    if(currentSum >= 10){
      rem = 1;
      currentSum %= 10;
    }else{
      rem = 0;
    }
    Node *newNode = new Node(currentSum);
    if(previous){
      previous->next = newNode;
    }else{
      newListHead = newNode;
    }
    previous = newNode;
    ptr2 = ptr2->next;
  }

  if(rem) previous->next = new Node(1);
  newList->m_head = newListHead;
  return newList;
}

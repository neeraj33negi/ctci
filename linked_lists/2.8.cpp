#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list = new LinkedList();
  list->BuildFromArgs(argc, argv);
  Node *loopNode = list->m_head;
  list->AddNode(2);
  list->AddNode(1);
  list->AddNode(3);
  Node *lastNode = list->LastNode();
  lastNode->next = loopNode;
  Node *loopedAt = list->DetectLoop();
  if(loopedAt != nullptr) cout << loopedAt->data;
  return 0;
}

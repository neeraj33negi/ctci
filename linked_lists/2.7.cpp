#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *commonList = new LinkedList();
  commonList->BuildFromArgs(argc, argv);
  LinkedList *list1 = new LinkedList(commonList);
  LinkedList *list2 = new LinkedList(commonList);
  list1->AddNode(2);
  list1->AddNode(1);
  list2->AddNode(6);
  list2->AddNode(7);
  list2->AddNode(8);
  Node *intersectionNode = list1->Intersection(commonList);
  cout << intersectionNode->data;
  return 0;
}

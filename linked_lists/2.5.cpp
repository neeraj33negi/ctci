#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list1 = new LinkedList();
  LinkedList *list2 = new LinkedList();
  list1->AddNode(5);
  // list1->AddNode(1);
  // list1->AddNode(7);
  // list1->AddNode(7);
  // list1->AddNode(7);
  // list2->AddNode(2);
  // list2->AddNode(9);
  list2->AddNode(5);
  list1->Print();
  list2->Print();
  LinkedList *list3 = list1->Add(list2);
  list3->Print();
  return 0;
}

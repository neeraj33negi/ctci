#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list1 = new LinkedList();
  LinkedList *list2 = new LinkedList();
  list1->BuildFromArgs(argc, argv);
  // list2->AddNodeLast(1);
  // list2->AddNodeLast(5);
  // list2->AddNodeLast(6);
  // list2->AddNodeLast(10);
  list1->Print();
  list2->Print();
  LinkedList *mergedList = list1->Merge(list2);
  mergedList->Print();
  return 0;
}

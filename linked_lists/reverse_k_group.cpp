#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list1 = new LinkedList();
  list1->BuildFromArgs(argc, argv);
  int k;
  cin >> k;
  list1->ReverseKGroup(k);
  list1->Print();
  return 0;
}

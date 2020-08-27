#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list1 = new LinkedList();
  list1->BuildFromArgs(argc, argv);
  list1->SwapPairs();
  list1->Print();
  return 0;
}

#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list = new LinkedList();
  list->BuildFromArgs(argc, argv);
  list->Print();
  list->RemoveDups();
  list->Print();
  return 0;
}

#include "linked_list.h"

LinkedList *BuildListFromArgs(int count, char **args){
  LinkedList *list = new LinkedList();
  int i = count;
  while(--i >= 1){
    list->AddNode( atoi(args[i]) );
  }
  return list;
}


int main(int argc, char **argv){
  LinkedList *list = BuildListFromArgs(argc, argv);
  list->Print();
  list->RemoveDups();
  list->Print();
  return 0;
}

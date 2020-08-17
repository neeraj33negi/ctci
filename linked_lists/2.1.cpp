#include "linked_list.h"

LinkedList *BuildListFromArgs(int count, char **args){
  LinkedList *list = new LinkedList();
  int i = 0;
  while(++i < count){
    list->AddNode( atoi(args[i]) );
  }
  return list;
}


int main(int argc, char **argv){
  LinkedList *list = BuildListFromArgs(argc, argv);
  list->Print();
  return 0;
}

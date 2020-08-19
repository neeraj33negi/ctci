#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list = new LinkedList();
  list->BuildFromArgs(argc, argv);
  list->Print();
  int k;
  cin >> k;
  cout << list->KthToLast(k);
  return 0;
}

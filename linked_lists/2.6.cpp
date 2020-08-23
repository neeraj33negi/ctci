#include "linked_list.h"

int main(int argc, char **argv){
  LinkedList *list = new LinkedList();
  list->BuildFromArgs(argc, argv);
  list->Print();
  list->IsPalindrome() ? cout << "Yes" : cout << "No";
  return 0;
}

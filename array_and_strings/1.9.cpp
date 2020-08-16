#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string &s1, string &s2){
  int len1 = s1.size();
  int len2 = s2.size();
  if(len2 > len1) return false;

  int idx = 0;
  for(int i = 0; i < len1; ++i){
    for(int j = 0; j < len2; ++j){
      if(s1[i] != s2[j]){
        break;
      }
      i++;
      if(j == len2 - 1) return true;
    }
  }
  return false;
}


bool isRotation(string &s1, string &s2){
  int len1 = s1.size();
  int len2 = s2.size();
  if(len1 != len2) return false;

  string temp = s1 + s1;
  return isSubstring(temp, s2);
}



int main(int argc, char **argv){
  string s1 = argv[1];
  string s2 = argv[2];
  isRotation(s1, s2) ? cout << "Yes" : cout << "No";
  return 0;
}

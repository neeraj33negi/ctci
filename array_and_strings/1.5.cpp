#include <iostream>
#include <string>

using namespace std;

bool OneAwayHelper(string &str1, string &str2, int i, int j, int diff){
  if(diff > 1) return false;
  if(( i >= str1.size() && j < str2.size()) || ( j >= str2.size() && i < str1.size())) return false;
  if(diff <=1 && i == str1.size() && j == str2.size()) return true;

  if(str1[i] == str2[j]) return OneAwayHelper(str1, str2, ++i, ++j, diff);
  return OneAwayHelper(str1, str2, ++i, j, ++diff) ||
         OneAwayHelper(str1, str2, ++i, ++j, ++diff) ||
         OneAwayHelper(str1, str2, i, ++j, ++diff);
}

bool OneAway(string &str1, string &str2){
  return OneAwayHelper(str1, str2, 0, 0, 0);
}

int main(int argc, char **argv){
  string str1 = argv[1];
  string str2 = argv[2];

  OneAway(str1, str2)? cout << "YES" : cout << "NO";
  return 0;
}

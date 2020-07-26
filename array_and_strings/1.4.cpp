#include <iostream>
#include <string>

using namespace std;

bool IsPalindromicPermutation(string &str){
  int bitmap[128] = {0};
  for(int i = 0; i < str.size(); ++i){
    if(str[i] != ' ')
      bitmap[tolower(str[i])]++;
  }
  int odds = 0;
  for(int i = 0; i < 128; ++i){
    if(bitmap[i]%2) odds++;
  }
  if(odds > 1) return false;
  return true;
}

int main(int argc, char **argv){
  string str;
  int len;
  getline(cin, str);
  IsPalindromicPermutation(str) ? cout << "YES" : cout << "NO";
  return 0;
}

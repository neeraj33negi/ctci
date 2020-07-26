#include <iostream>
#include <string>

using namespace std;

bool OneAway(string &str1, string &str2){
  int len1 = str1.size();
  int len2 = str2.size();
  int replace = 0, insert = 0;
  int i = 0, j = 0;
  while(i < len1 && j < len2){
    if(str1[i] == str2[j]){
      ++i, ++j;
      continue;
    }
    if(len1 == len2){
      ++i, ++j;
      ++replace;
    } else {
      ++insert;
      if(len1 > len2){
        ++i;
      }else{
        ++j;
      }
    }
  }
  if(i < len1 && j == len2){
    while(i++ < len1) ++insert;
  }
  if(j < len2 && i == len1){
    while(j++ < len2) ++insert;
  }
  return (replace + insert <= 1);
}

int main(int argc, char **argv){
  string str1 = argv[1];
  string str2 = argv[2];

  OneAway(str1, str2)? cout << "YES" : cout << "NO";
  return 0;
}

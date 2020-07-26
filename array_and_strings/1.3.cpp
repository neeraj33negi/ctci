#include <iostream>
#include <string>

using namespace std;

void URLify(string &str, int len){
  int totalSpaces = 0;
  for(int i = 0;i < len; ++i){
    if(str[i] == ' ') totalSpaces++;
  }
  int idx = len - 1;
  int endIdx;
  while(totalSpaces){
    for(; str[idx] != ' ' && idx >= 0; --idx){
      endIdx = idx + 2*totalSpaces;
      str[endIdx] = str[idx];
    }
    str[--endIdx] = '0';
    str[--endIdx] = '2';
    str[--endIdx] = '%';
    idx--;
    totalSpaces--;
  }
}

int main(int argc, char **argv){
  string str;
  int len;
  getline(cin, str);
  cin >> len;
  URLify(str, len);
  cout << str;
  return 0;
}
// 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
// m,r, ,j,o,h,n, ,s,m,\i,\t,\h
// m,r, ,j,o,h,n, ,s,m,\i,\t\,s,\m,\i,\t,\h
// m,r,%,2,0,j,o,h,n,%,\2,\0,\s,\m,\i,\t,\h

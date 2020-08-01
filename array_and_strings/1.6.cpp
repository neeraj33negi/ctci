#include <iostream>
#include <string>
using namespace std;

string Compress(string str){
  string str2 = "";
  int count = 1;
  str2 += char(str[0]);
  for(int i = 1; i < str.size(); ++i){
    if(str[i] == str[i-1]){
      ++count;
    } else {
      str2 += to_string(count);
      str2 += char(str[i]);
      count = 1;
    }
  }
  str2 += to_string(count);
  if(str2.size() > str.size()) return str;
  return str2;
}

int main(int argc, char **argv){
  string str = argv[1];

  cout << Compress(str);
  return 0;
}

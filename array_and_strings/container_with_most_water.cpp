#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetArrFromArgs(int argc, char **args){
  vector<int> array;
  int i = 0;
  while(++i < argc){
    array.push_back(atoi(args[i]));
  }
  return array;
}

void PrintArray(vector<int> &arr){
  for(int i : arr){
    cout << i << " ";
  }
  cout << endl;
}

int MaxArea(vector<int> &heights){
  int left = 0, right = heights.size() - 1;
  int maxSeen = (right - left) * min(heights[left], heights[right]);
  int current;
  while(left < right){
    if(heights[left] < heights[right]){
      left++;
    }else{
      right--;
    }
    current = (right - left) * min(heights[left], heights[right]);
    if(current > maxSeen) maxSeen = current;
  }
  return maxSeen;
}

int main(int argc, char **argv){
  vector<int> heights = GetArrFromArgs(argc, argv);
  cout << MaxArea(heights);
  return 0;
}

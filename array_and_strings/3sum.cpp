#include <iostream>
#include <vector>
#include <unordered_map>
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

void PrintSolution(vector<vector<int> > &solutionArr){
  for(auto arr : solutionArr){
    PrintArray(arr);
  }
}

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

vector<vector<int> > ThreeSum(vector<int> &arr){
  unordered_map<int, bool> finder;
  vector<vector<int> > solutionArr;
  int k;
  for(int i = 0; i < arr.size(); ++i){
    int k = -arr[i];
    for(int j = i + 1; j < arr.size(); ++j){
      if(finder.find(arr[j]) == finder.end()){
        finder[arr[j]] = k - arr[j];
      }else{
        vector<int> sol = {arr[i], arr[j], k - arr[j]};
        PrintArray(sol);
        solutionArr.push_back(sol);
      }
    }
    solutionArr.clear();
  }
  return solutionArr;
}

int main(int argc, char **argv){
  vector<int> arr = GetArrFromArgs(argc, argv);
  vector<vector<int> > solutionArr = ThreeSum(arr);
  PrintSolution(solutionArr);
  return 0;
}

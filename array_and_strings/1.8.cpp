#include <iostream>
#include <vector>

using namespace std;

void PrintMatrix(vector< vector<int> > &matrix){
  for(auto row : matrix){
    for(auto num : row){
      cout << num << " ";
    }
    cout << "\n";
  }
}

void GetMatrix(vector< vector<int> > &matrix, int rowLen, int colLen){
  int num;
  for(int i = 0; i < rowLen; ++i){
    vector<int> row;
    for(int j = 0; j < colLen; ++j){
      cin >> num;
      row.push_back(num);
    }
    matrix.push_back(row);
  }
}

// Version1 - O(m+n) space, quad time
void SetZeroes(vector< vector<int> > &matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  vector<int> rows;
  vector<int> cols;
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
      if(!matrix[i][j]){
        rows.push_back(i);
        break;
      }
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(!matrix[j][i]){
        cols.push_back(i);
        break;
      }
    }
  }

  for(int i = 0; i < rows.size(); ++i){
    for(int j = 0; j < n ; ++j) matrix[rows[i]][j] = 0;
  }

  for(int i = 0; i < cols.size(); ++i){
    for(int j = 0; j < m ; ++j) matrix[j][cols[i]] = 0;
  }
}

// Constant space
void setZeroes(vector< vector<int> > &matrix){
  int m = matrix.size();
  int n = matrix[0].size();

  bool firstRow = false;
  bool firstCol = false;

  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
      if(!matrix[i][j]){
        if(!i) firstRow = true;
        if(!j) firstCol = true;
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for(int i = 1; i < m; ++i){
    if(!matrix[i][0]){
      for(int j = 1; j < n; ++j){
        matrix[i][j] = 0;
      }
    }
  }


  for(int i = 1; i < n; ++i){
    if(!matrix[0][i]){
      for(int j = 1; j < m; ++j){
        matrix[j][i] = 0;
      }
    }
  }
  if(firstRow) for(int i = 0; i < n; ++i) matrix[0][i] = 0;
  if(firstCol) for(int i = 0; i < m; ++i) matrix[i][0] = 0;
}

int main(int argc, char **argv){
  int rowLen = atoi(argv[1]);
  int colLen = atoi(argv[2]);
  vector< vector<int> > matrix;
  GetMatrix(matrix, rowLen, colLen);
  setZeroes(matrix);
  PrintMatrix(matrix);
  return 0;
}

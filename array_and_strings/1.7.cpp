#include <iostream>
#include <vector>

#define SWAP(x, y) { int temp = a; a = b; b = temp;}

using namespace std;

void PrintImage(vector< vector<int> > &image){
  for(auto row : image){
    for(auto pixel : row){
      cout << pixel << " ";
    }
    cout << "\n";
  }
}

void GetImage(vector< vector<int> > &image, int size){
  int pixel;
  for(int i = 0; i < size; ++i){
    vector<int> row;
    for(int j = 0; j < size; ++j){
      cin >> pixel;
      row.push_back(pixel);
    }
    image.push_back(row);
  }
}

// Version 1, O(n^2) space and time
vector< vector<int> > RotateImage(vector< vector<int> > &image){
  int dim = image[0].size();
  vector< vector<int> > out;
  for(int i = 0; i < dim; ++i){
    vector<int> row;
    for(int j = dim - 1 ; j >= 0; --j){
      row.push_back(image[j][i]);
    }
    out.push_back(row);
  }
  return out;
}

// Version 2, in place, O(1) space and quad time
void RotateImageInPlace(vector< vector<int> > &image){
  int dim = image[0].size(), temp;
  for(int i = 0; i < dim; ++i){
    for(int j = i + 1; j < dim; ++j){
      temp = image[i][j];
      image[i][j] = image[j][i];
      image[j][i] = temp;
    }
  }

  for(int i = 0; i < dim; ++i){
    for(int j = 0; j < dim / 2; ++j){
      temp = image[i][j];
      image[i][j] = image[i][dim-1-j];
      image[i][dim-1-j] = temp;
    }
  }
}

int main(int argc, char **argv){
  int size = atoi(argv[1]);
  vector< vector<int> > image;
  GetImage(image, size);
  // PrintImage(image);
  vector< vector<int> > rotated = RotateImage(image);
  PrintImage(rotated);
  RotateImageInPlace(image);
  PrintImage(image);
  return 0;
}

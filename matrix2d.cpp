#include<iostream>
#include<climits>
using namespace std;

int  colsum(int mat[][3], int row, int col) {
  int maxcolsum=INT_MIN;
  for(int i=0;i<col;i++){
    int colsum=0;
    for(int j=0;j<row;j++){
      colsum+=mat[i][j];
    }
    maxcolsum=max(maxcolsum,colsum);
  }
  return maxcolsum;
}
      


int main() {
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int row = 3;
    int col = 3;
    int key = 14;

   cout<<" "<< colsum(mat,row,col);

  
    return 0;
}
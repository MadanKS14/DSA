#include<iostream>
#include<vector>
using namespace std;

void selection(vector<int> &arr ,int n){
  for(int i=0;i<n-1;i++){
    int sidx=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]>arr[sidx]){
        sidx=j;
      }
          swap(arr[j],arr[sidx]);
    } 
  }
}

void print(vector<int> &arr ,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}
int main(){
  vector<int> arr={4,1,5,3,2};
  int n=arr.size();
  selection(arr,n);
  print(arr,n);
}
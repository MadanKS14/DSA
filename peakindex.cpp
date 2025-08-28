#include<iostream>
#include<vector>
using namespace std;

int peakindex(vector<int> &arr){
  int n=arr.size();
  int high=n-1;
  int low=0;

  while(low<high){
    int mid =(high+low)/2;
    if(arr[mid]<arr[mid+1]){
      low=mid+1;
    }else{
      high=mid;
    }
  }
  return low;
}

int main(){
  vector<int> arr={0,2,4,6,5,3,1};
  cout<<peakindex(arr);

  return 0;
}
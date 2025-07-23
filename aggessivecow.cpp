#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
using namespace std;



bool isValid(vector<int> &arr, int n,int m,int maxA){
  int cows=1,pos=arr[0];
 for(int i=0;i<n;i++){
  if((arr[i]-pos)>=maxA){
    cows++;
    pos=arr[i];
  }
  if(cows==m) return true;
 }
 return false;
}



int getDistance(vector<int> &arr, int n,int m){
  sort(arr.begin(),arr.end());
  int start=arr[0],end=arr[n-1],ans=-1;
  while(start<=end){
    int mid=start+(end-start)/2;
    if(isValid(arr,n,m,mid)){
      ans=mid;
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  return ans;
}
 
int main(){

  vector<int> arr={1,2,8,4,9};
  int n=5,m=3;
  cout<<getDistance(arr,n,m);
  return 0;
}
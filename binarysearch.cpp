#include<iostream>
#include<vector>
using namespace std;

int bsearch(vector<int> &nums,int target){
  int n=nums.size();
  int start=0;
  int end=n-1;
  while(start<=end){
    int mid = start+(end-start)/2;
    if(target==nums[mid]){
      return mid;
    }
    else if(target<nums[mid]){
      end=mid-1;
    }
    else{
      start=mid+1;
    }
  }
  return -1;
}

int main(){
  vector<int> nums={1,4,7,8,13,45,67,89,99};
  int target= 7;
  int idx= bsearch(nums,target);
  if( idx!= -1){
    cout<<"key found at :"<<idx<<endl;
  }else{
    cout<<"key not found"<< endl;
  }
  
  return 0;
}
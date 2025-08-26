#include<iostream>
#include<vector>
using namespace std;

int bsearch(vector<int> &nums,int target){
  int n=nums.size();
  int start=0;
  int end=n-1;
  while(start<=end){
    int mid = (start+end)/2;
    if(target>nums[mid]){
      start=mid+1;
    }
    else if(target<nums[mid]){
      end=mid-1;
    }
    else{
      return mid;
    }
  }
}

int main(){
  vector<int> nums={1,4,7,8,13,45,67,89,99};
  int target= 99;
  cout<<"key found at :"<<bsearch(nums,target);
  return 0;
}
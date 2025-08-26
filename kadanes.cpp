#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int subarr(vector<int> &nums){
  int n=nums.size();
  int maxsum = INT_MIN;
  int cursum=0;
  for(int num:nums){
    cursum+=num;
    maxsum=max(maxsum,cursum);
    if(cursum<0){
      cursum=0;
    }
  }
  return maxsum;
}

int main(){

  vector<int> nums={-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout<<"maximum subarray sum is :"<<subarr(nums)<<endl;
  return 0;
}
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int subarr(vector<int> &nums){
  int n=nums.size();
  int maxsum = INT_MIN;

  for(int start=0;start<n;start++){
    int currsum=0;
    for(int end=start ;end<n;end++){
      currsum+=nums[end];
      maxsum=max(maxsum,currsum);
    }
  }
  return maxsum;
}

int main(){

  vector<int> nums={-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout<<"maximum subarray sum is :"<<subarr(nums)<<endl;
  return 0;
}
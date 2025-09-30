#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> duplicate(vector<int>&arr){
  int n=arr.size();
  unordered_map<int,int>mp;
  vector<int> ans(n);

  for(int i=0;i<n;i++){
    mp[arr[i]]++;
  }

  for(auto p:&mp){
    if(mp.find(p)!=mp.end()){
      ans.push_back(mp[p]);

    }
  }
  return ans;

}

int main(){

  vector<int>arr={3,6,6,8,8,9,9,1,2};

  int res=duplicate(arr);
  for(int f:res){
    cout<<f<<" ";
  }

  return 0;
}
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int besttime(vector<int> &stocks){
  int n=stocks.size();
  int maxprice=0;
  int minprice=INT_MAX;

  for(int i=0;i<n;i++){
    minprice=min(minprice,stocks[i]);

    int profit=stocks[i]-minprice;

    maxprice=max(maxprice,profit);
   
  }
  return maxprice;
}

int main(){
  vector<int> stocks={7,1,5,3,6,4};
  cout<<besttime(stocks);
  return 0;
}
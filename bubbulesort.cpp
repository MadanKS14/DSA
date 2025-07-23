#include<iostream>
using namespace std;

void bubblesort(int a[],int n){
  bool isSwap;
  for(int i=0;i<n-1;i++){
      bool isSwap=false;
    for(int j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
        isSwap=true;
      }
    }
   
  }
   if(!isSwap) return;
}

void printarray(int a[],int n){
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  
}

int main(){
  int a[]={3,5,7,1,2};
  int n=5;
  bubblesort(a,n);
  printarray(a,n);
}
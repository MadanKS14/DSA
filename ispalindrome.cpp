#include<iostream>
#include<cctype>
#include<string>

using namespace std;

bool isPalindrome(const string  &str){
  int left=0,right=str.length()-1;
  while(left<right){
    if(str[left]!=str[right]){
      return false;
    }
      left++;
      right--;
  
  }
  return true;
}

void Palindrome(const string &input){
  string clean="";
  for(char c:input){
    if(isalnum(c)){
      clean+=tolower(c);
    }
  }
  if(isPalindrome(clean)){
    cout<<"it is palindrome ";
  }
  else{
    cout<<"its not a palindrome";
  }
}

int main(){
  string input="A man, a plan, a canal: Panama";
  Palindrome(input);
  return 0;
}
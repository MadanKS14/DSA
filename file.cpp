#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main(){

  vector<int> arr(5);
  ofstream fout;
  fout.open("zero.txt");

  cout<<"Enter numbers :"<<endl;
  fout<<" original numbers : ";
  for(int i=0;i<5;i++){
    cin>>arr[i];
    fout<<arr[i]<<" ";
  }

  fout.close();

  
  ifstream fin("zero.txt");
   string line;
    cout << "\nReading from file:" << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
    return 0;
}
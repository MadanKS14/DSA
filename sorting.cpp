// #include <iostream>
// #include <vector>
// using namespace std;

// void bubblesort(vector<int> &arr)
// {
//   int n = arr.size();

//   for (int i= 0; i < n - 1; i++)
//   {
//     for (int j=0; j < n - i - 1; j++)
//     {
//       if (arr[j] > arr[j + 1])
//       {
//         int temp = arr[j];
//         arr[j] = arr[j + 1];
//         arr[j + 1] = temp;
//       }
//     }
//   }
// }

// int main()
// {
//   vector<int> arr = {5, 3, 8, 4, 2};
//   int n=arr.size();

//   cout << "before sorting :" << endl;
//   for (int i = 0; i < n; i++)
//   {
//     cout << arr[i] << " ";
//   }

//   bubblesort(arr);

//   cout << "before sorting :" << endl;
//   for (int i = 0; i < n; i++)
//   {
//     cout << arr[i] <<" ";
//   }

//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// void selectionsort(vector<int> &arr)
// {
//   int n = arr.size();

//   for(int i=0;i<n;i++){
//     int min=i;
//     for(int j=i+1;j<n;j++){
//       if(arr[j]<arr[min]){
//         min=j;
//       }
//     }
//     swap(arr[i],arr[min]);
//   }

// }

// int main()
// {
//   vector<int> arr = {5, 3, 8, 4, 2};
//   int n=arr.size();

//   cout << "before sorting :" << endl;
//   for (int i = 0; i < n; i++)
//   {
//     cout << arr[i] << " ";
//   }

//   selectionsort(arr);

//   cout << "before sorting :" << endl;
//   for (int i = 0; i < n; i++)
//   {
//     cout << arr[i] <<" ";
//   }

//   return 0;
// }






// #include <iostream>
// #include <vector>
// using namespace std;

// void insertionsort(vector<int> &arr)
// {
//   int n = arr.size();

//   for (int i = 1; i < n; i++)
//   {
//     int j = i - 1;
//     int key = arr[i];

//     while (j >= 0 && arr[j] > key)
//     {
//       arr[j + 1] = arr[j];
//       j--;
//     }
//     arr[j + 1] = key;
//   }
// }

// int main()
// {
//   vector<int> arr = {5, 3, 8, 4, 2};
//   int n = arr.size();

//   cout << "before sorting :" << endl;
//   for (int i = 0; i < n; i++)
//   {
//     cout << arr[i] << " ";
//   }

//   insertionsort(arr);

//   cout << "before sorting :" << endl;
//   for (int i = 0; i < n; i++)
//   {
//     cout << arr[i] << " ";
//   }

//   return 0;
// }
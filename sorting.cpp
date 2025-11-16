#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<int> &arr)
{
  int n = arr.size();

  for (int i= 0; i < n - 1; i++)
  {
    for (int j=0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  vector<int> arr = {5, 3, 8, 4, 2};
  int n=arr.size();

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  bubblesort(arr);

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] <<" ";
  }

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void selectionsort(vector<int> &arr)
{
  int n = arr.size();

  for(int i=0;i<n;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[min]){
        min=j;
      }
    }
    swap(arr[i],arr[min]);
  }

}

int main()
{
  vector<int> arr = {5, 3, 8, 4, 2};
  int n=arr.size();

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  selectionsort(arr);

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] <<" ";
  }

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int> &arr)
{
  int n = arr.size();

  for (int i = 1; i < n; i++)
  {
    int j = i - 1;
    int key = arr[i];

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main()
{
  vector<int> arr = {5, 3, 8, 4, 2};
  int n = arr.size();

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  insertionsort(arr);

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
  int i = st;
  int j = mid + 1;
  vector<int> temp;
  while (i <= mid && j <= end)
  {
    if (arr[i] < arr[j])
    {
      temp.push_back(arr[i]);
      i++;
    }
    else
    {
      temp.push_back(arr[j]);
      j++;
    }
  }

  while (i <= mid)
  {
    temp.push_back(arr[i]);
    i++;
  }
  while (j <= end)
  {
    temp.push_back(arr[j]);
    j++;
  }

  for (int idx = 0; idx < temp.size(); idx++)
  {
    arr[st + idx] = temp[idx];
  }
}

void mergesort(vector<int> &arr, int st, int end)
{
  if (st < end)
  {
    int mid = st + (end - st) / 2;
    mergesort(arr, st, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, st, mid, end);
  }
}

int main()
{
  vector<int> arr = {5, 3, 8, 4, 2};
  int n = arr.size();

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout << " " << endl;
  mergesort(arr, 0, arr.size() - 1);

  cout << "after sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
  int idx = st - 1;
  int pivot = arr[end];
  for (int j = st; j < end; j++)
  {
    if (arr[j] < pivot)
    {
      idx++;
      swap(arr[j], arr[idx]);
    }
  }
  idx++;
  swap(arr[end], arr[idx]);
  return idx;
}

void quicksort(vector<int> &arr, int st, int end)
{
  if (st < end)
  {
    int pivIdx = partition(arr, st, end);
    quicksort(arr, st, pivIdx - 1);
    quicksort(arr, pivIdx + 1, end);
  }
}

int main()
{
  vector<int> arr = {5, 2, 6, 4, 1, 3};
  int n = arr.size();

  cout << "before sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout << " " << endl;
  quicksort(arr, 0, arr.size() - 1);

  cout << "after sorting :" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}
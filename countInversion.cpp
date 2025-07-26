#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end) {
    int i = st, j = mid + 1;
    vector<int> temp;
    int count = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            count += (mid - i + 1); // All remaining elements in left are greater
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        arr[st + k] = temp[k];
    }
    return count;
}

int mergeSort(vector<int> &arr, int st, int end) {
    int inv_count = 0;
    if (st < end) {
        int mid = st + (end - st) / 2;
        inv_count += mergeSort(arr, st, mid);
        inv_count += mergeSort(arr, mid + 1, end);
        inv_count += merge(arr, st, mid, end);
    }
    return inv_count;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int inv = mergeSort(arr, 0, arr.size() - 1);
    cout << "Inversion count: " << inv << endl;
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int st, int end) {
    int idx = st - 1;
    int pivot = arr[end];

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);

    return idx;
}

void qs(vector<int>& arr, int st, int end) {
    if (st < end) {
        int pivotIdx = partition(arr, st, end);
        qs(arr, st, pivotIdx - 1);
        qs(arr, pivotIdx + 1, end);
    }
}

int main() {
    vector<int> arr = {5, 2, 3, 4, 1};
    qs(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> duplicate(vector<int> &num) {
    int n = num.size();
    vector<int> ans;
    unordered_set<int> seen;  
    for (int i = n - 1; i >= 0; i--) {
        if (seen.find(num[i]) == seen.end()) {
            ans.push_back(num[i]);
            seen.insert(num[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> num = {1, 2, 2, 3, 1};
    vector<int> result = duplicate(num);

    for (int m : result) {
        cout << m << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> product(vector<int> &nums)
{
  int n = nums.size();

  vector<int> ans(n);

  for (int i = 0; i < n; i++)
  {
    int prod = 1;
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        prod *= nums[j];
      }
    }
    ans[i] = prod;
  }
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  vector<int> result = product(nums);

  cout << "product of the array except itself is:" << endl;

  for (int x : result)
  {
    cout << x << " ";
  }

  return 0;
}
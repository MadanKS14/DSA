#include <iostream>
#include <vector>
using namespace std;

vector<int> product(vector<int> &nums)
{
  int n = nums.size();

  vector<int> ans(n, 1);
  int prefix = 1;
  for (int i = 0; i < n; i++)
  {
    ans[i] = prefix;
    prefix *= nums[i];
  }

  int suffix = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    ans[i] *= suffix;
    suffix *= nums[i];
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
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int container(vector<int> &height)
{
  int n = height.size();
  int maxwater=INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int area = min(height[i], height[j]) * (j - i);
      maxwater = max(maxwater, area);
    }
  }
  return maxwater;
}

int main()
{
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << "container with most water is :" << container(height);
  return 0;
}
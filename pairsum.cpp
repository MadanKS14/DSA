#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    vector<int> ans;

    while (i < j)
    {
        int sum = nums[i] + nums[j];

        if (sum == target)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = pairsum(nums, target);

    if (!result.empty())
    {
        cout << "Pair found at indices: ";
        for (int idx : result)
            cout << idx << " ";
    }
    else
    {
        cout << "No pair found!";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fn(vector<int> &nums, int index)
    {
        if (index < 0)
            return 0;
        if (index == 0)
            return nums[0];

        int pick = fn(nums, index - 2) + nums[index];
        int notpick = fn(nums, index - 1);

        return max(pick, notpick);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        return fn(nums, n - 1);
    }
};

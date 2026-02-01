#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fn(vector<int> &nums, int index, vector<int> &dp)
    {
        if (index < 0)
            return 0;
        if (index == 0)
            return nums[0];
        if (dp[index] != -1)
            return dp[index];

        int pick = fn(nums, index - 2, dp) + nums[index];
        int notpick = fn(nums, index - 1, dp);

        return dp[index] = max(pick, notpick);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(nums.size(), -1);

        return fn(nums, nums.size() - 1, dp);
    }
};

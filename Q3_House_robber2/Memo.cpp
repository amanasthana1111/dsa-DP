#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(vector<int>& nums, int index, vector<int>& dp) {
        if (index < 0) return 0;
        if (index == 0) return nums[0];
        if (dp[index] != -1) return dp[index];

        int pick = fn(nums, index - 2, dp) + nums[index];
        int notpick = fn(nums, index - 1, dp);

        return dp[index] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> firstH, lastH;

        for (int i = 0; i < n; i++) {
            if (i != 0) lastH.push_back(nums[i]);      // [1 ... n-1]
            if (i != n - 1) firstH.push_back(nums[i]); // [0 ... n-2]
        }

        vector<int> dp1(lastH.size(), -1);
        vector<int> dp2(firstH.size(), -1);

        return max(
            fn(lastH, lastH.size() - 1, dp1),
            fn(firstH, firstH.size() - 1, dp2)
        );
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(vector<int>& nums, int index) {
        if (index < 0) return 0;
        if (index == 0) return nums[0];

        int pick = fn(nums, index - 2) + nums[index];
        int notpick = fn(nums, index - 1);

        return max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> firstH, lastH;

        // exclude first house
        for (int i = 1; i < n; i++)
            lastH.push_back(nums[i]);

        // exclude last house
        for (int i = 0; i < n - 1; i++)
            firstH.push_back(nums[i]);

        return max(
            fn(lastH, lastH.size() - 1),
            fn(firstH, firstH.size() - 1)
        );
    }
};

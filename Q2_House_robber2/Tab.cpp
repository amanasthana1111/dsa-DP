#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> firstH(nums.begin(), nums.end() - 1); // [0...n-2]
        vector<int> lastH(nums.begin() + 1, nums.end());  // [1...n-1]

        return max(robLinear(firstH), robLinear(lastH));
    }
};


// space
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int robLinear(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         if (n == 1) return nums[0];

//         int prev2 = nums[0];                  // dp[i-2]
//         int prev1 = max(nums[0], nums[1]);    // dp[i-1]

//         for (int i = 2; i < n; i++) {
//             int curr = max(prev1, nums[i] + prev2);
//             prev2 = prev1;
//             prev1 = curr;
//         }
//         return prev1;
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];

//         vector<int> firstH(nums.begin(), nums.end() - 1);
//         vector<int> lastH(nums.begin() + 1, nums.end());

//         return max(robLinear(firstH), robLinear(lastH));
//     }
// };

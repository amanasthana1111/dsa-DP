class Solution {
public:
//recurrsion
    // int fn(int m , int n){
    //     if(m == 0 && n==0){
    //         return 1;
    //     }
    //     if(m<0 || n<0) return 0;
    //     int top = fn(m-1 , n);
    //     int left = fn(m , n-1);
    //     return top + left;
    // }

    int fn(int m , int n,vector<vector<int>>&dp){
        if(m == 0 && n==0){
            return 1;
        }
        
        if(m<0 || n<0) return 0;
        if(dp[m][n]!= -1) return dp[m][n];
        int top = fn(m-1 , n,dp);
        int left = fn(m , n-1,dp);
        return dp[m][n] =  top + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fn(m - 1, n - 1,dp);
    }
};
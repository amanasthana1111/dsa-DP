#include <bits/stdc++.h>
using namespace std;

// Function declaration
long long fibonacci(int n, vector<long long> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    int left = fibonacci(n - 1, dp);
    int right = fibonacci(n - 2, dp);
    return dp[n] = left + right;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<long long> dp(n + 1, -1);

    cout << "fibonacci of " << n << " is: " << fibonacci(n,dp) << endl;

    return 0;
}

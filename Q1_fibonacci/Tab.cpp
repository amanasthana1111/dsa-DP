#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // DP table
    vector<long long> dp(n + 1);

    // Base cases
    if (n >= 0) dp[0] = 0;
    if (n >= 1) dp[1] = 1;

    // Fill table
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci of " << n << " is: " << dp[n] << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Function declaration
long long fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int left = fibonacci(n-1);
    int right = fibonacci(n-2);
    return left + right;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "fibonacci of " << n << " is: " << fibonacci(n) << endl;

    return 0;
}

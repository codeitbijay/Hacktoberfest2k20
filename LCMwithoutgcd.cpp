
// C++ program to find LCM of 2 numbers
// without using GCD
#include <bits/stdc++.h>
using namespace std;

// Function to return LCM of two numbers
int findLCM(int a, int b)
{
    int lar = max(a, b);
    int small = min(a, b);
    for (int i = lar; ; i += lar) {
        if (i % small == 0)
            return i;
    }
}

// Driver program to test above function
int main()
{
    int a = 5, b = 7;
    cout << "LCM of " << a << " and "
         << b << " is " << findLCM(a, b);
    return 0;
}

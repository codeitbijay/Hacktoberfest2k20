// To find to Minimum difference between any two elements
// -by Imakshat47

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// #define INT_MAX 2147483647
int findMinonOn2(int a[], int n)
{
    int diff = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++i)
        {
            if (abs(a[j] - a[j + 1]) < diff)
                diff = abs(a[j] - a[j + 1]);
        }
    }
    return diff;
}

int findMinonOn1(int a[], int n)
{
    sort(a, a + n);
    int diff = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i + 1] - a[i]) < diff)
            diff = a[i + 1] - a[i];
    }

    return diff;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        printf("Function Call...");
        printf("%d", findMinonOn2(a, n));
        // printf("%d", findMinonOn1(a, n));
    }
    return 0;
}
// Remove some elements and sort Array
// - by Imakshat47
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int A[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &A[i]);

        int l = 1;
        
        for (int i = 1; i < n; ++i)
        {
            if (A[l - 1] <= A[i])
            {
                A[l] = A[i];
                ++l;
            }
        }

        for (int i = 0; i < l; i++)
        {
            printf("%d ", A[i]);
        }
    }

    return 0;
}
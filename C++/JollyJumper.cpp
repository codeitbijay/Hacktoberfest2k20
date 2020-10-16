/*
    -by Imakshat47
    Joly Jumper
*/
#include <iostream>
using namespace std;

int jollyJumper()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 1; i < n - 1; ++i)
        scanf("%d", A[i]);
    int ndiff = 0, diff = abs(A[0] - A[1]), pval = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if (i == 1)
        {
            pval = ndiff - diff;
            if (abs(pval) != 1)
                return 0;
        }
        if (i > 1)
        {
            if (diff - ndiff != pval)
                return 0;
        }
        diff = ndiff;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        if (jollyJumper())
            printf("Joly");
        else
            printf("Not Joly");
    }

    return 0;
}
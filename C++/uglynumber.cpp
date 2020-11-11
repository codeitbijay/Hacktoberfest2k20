#include <bits/stdc++.h>

using namespace std;

void findugly(int n)
{
    long int ugly[n];
    ugly[0] = 1;
    long int i2 = 0, i5 = 0, i3 = 0;
    long int nextugly2 = 2, nextugly3 = 3, nextugly5 = 5;
    long int nextugly = 1;

    for(int i = 1; i<n; i++)
    {
        nextugly = min(nextugly2, min(nextugly3, nextugly5));
        ugly[i] = nextugly;

        if(nextugly == nextugly2)
        {
            i2++;
            nextugly2 = ugly[i2] * 2 ;

        }

        if(nextugly3 == nextugly)
        {
            i3++;
            nextugly3 = ugly[i3] * 3 ;

        }

        if(nextugly5 == nextugly)
        {
            i5++;
            nextugly5 = ugly[i5] * 5;

        }
    }
    cout<<ugly[n-1]<<endl;

}

int main()
 {
	int t;
	cout<<"Enter the number of test cases."<<endl;
	cin>>t;
	while(t--)
	{
	    cout<<"Enter the value of n."<<endl;
	    int n;
	    cin>>n;
	    findugly(n);
	}
	return 0;
}

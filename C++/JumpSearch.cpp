
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{
        int step = sqrt(n);

    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

int main()
{
    int t;
    cout<<"Enter the number of test cases."<<endl;
    cin>>t;
    while(t--)
    {

        int n;
        cout<<"Enter size of the array."<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the elements of the sorted array."<<endl;
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }
        int x;
        cout<<"Enter the element to be searched."<<endl;
        cin>>x;
        int index = jumpSearch(arr, x, n);
        cout << "\nNumber " << x << " is at index " << index;
        return 0;

    }

}

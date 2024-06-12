#include <iostream>
using namespace std;

int main()
{
    int i, n;

    cout << "Enter total number of elements";
    cin >> n;

    int arr[n];
    for(i = 0; i < n; i++)
    {
       cin >> arr[i];
    }

    int mx=arr[0];
    for(i = 1;i < n; ++i)
    {
       // Change < to > if you want to find the smallest element
       if(mx < arr[i])
           mx = arr[i];
    }
    cout << "Largest element = " << mx;
    return 0;
}

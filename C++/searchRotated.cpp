//Search in a rorated array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int search1(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[l] <= arr[mid]) {

        if (key >= arr[l] && key <= arr[mid])
            return search1(arr, l, mid - 1, key);
        return search1(arr, mid + 1, h, key);
    }
    if (key >= arr[mid] && key <= arr[h])
        return search1(arr, mid + 1, h, key);

    return search1(arr, l, mid - 1, key);

}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int key;
        cin>>key;
        int i = search1(A, 0, N - 1, key);
        if (i != -1)
            cout << i << endl;
        else
            cout << "-1"<<endl;

    }
}
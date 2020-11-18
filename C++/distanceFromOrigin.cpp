/**********************************************************************************************************
Maximum distance of end point from origin such that there are increments only in x and y direcetion 
consecutively with no. of increments in 1st line of input and increment amounts in 2nd line .
***********************************************************************************************************/

#include <iostream>
#include <bits/stdc++.h> 
#include <cmath>
using namespace std;
 
int main(){
    long long int n=0, sum=0, s=0, y=0, dis=0;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    sort(a,a+n );
    
    for(long long int i=0;i<n;i++){
        sum = sum + a[i];
    }
    
    for(long long int i=0; i<(n/2); i++){
        s= s+ a[i];
    }
    
    y = sum - s;
    dis = pow(y,2) + pow(s,2);
    cout << dis << endl;
    return 0;
}

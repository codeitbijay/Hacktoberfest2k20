// C++ program to find LCM of n elements 
#include <bits/stdc++.h> 
using namespace std; 


// GCD of two number
int gcd(int x, int y) 
{ 
	if (y == 0) 
		return x; 
	return gcd(y, x % y); 
} 

  //LCM of array
long long int findlcm(int arr[], int n) 
{ 
	                                              // Initialize answer 
	long long int ans = arr[0]; 
  
	for (int i = 1; i < n; i++) 
		ans = (((arr[i] * ans)) / 
				(gcd(arr[i], ans))); 

	return ans; 
} 

int main() 
{ 
	int arr[] = { 2, 7, 3, 9, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<findlcm(arr, n); 
	return 0; 
} 

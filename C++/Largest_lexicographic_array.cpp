// C++ program to find lexicographically 
// maximum value after k swaps. 
#include <bits/stdc++.h> 
using namespace std; 

// Function which modifies the array 
void KSwapMaximum(int arr[], int n, int k) 
{ 
	for (int i = 0; i < n - 1 && k > 0; ++i) { 

		// Here, indexPositionition is set where we 
		// want to put the current largest integer 
		int indexPosition = i; 
		for (int j = i + 1; j < n; ++j) { 

			// If we exceed the Max swaps 
			// then break the loop 
			if (k <= j - i) 
				break; 

			// Find the maximum value from i+1 to 
			// max k or n which will replace 
			// arr[indexPosition] 
			if (arr[j] > arr[indexPosition]) 
				indexPosition = j; 
		} 

		// Swap the elements from Maximum indexPosition 
		// we found till now to the ith index 
		for (int j = indexPosition; j > i; --j) 
			swap(arr[j], arr[j - 1]); 

		// Updates k after swapping indexPosition-i 
		// elements 
		k -= indexPosition - i; 
	} 
} 

// Driver code 
int main() 
{ 
	int n,k;
  cin>>n>>k;
  int A[n];
  for(int i=0;i<n;i++)
    cin>>A[i];

	KSwapMaximum(arr, n, k); 

	// Print the final Array 
	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
} 

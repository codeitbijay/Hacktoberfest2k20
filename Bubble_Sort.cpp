//C++ program for implementation of Bubble sort 
#include <bits/stdc++.h> 
using namespace std; 
// A function to swap the two numbers
void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int array[], int size) 
{  
	for (int i = 0; i < size-1; i++)	 
	
	// Last i elements are already in place 
	for (int j = 0; j < size-i-1; j++) 
		if (array[j] > array[j+1]) 
			swap(&array[j], &array[j+1]); 
} 

// Function to print an array
void printArray(int array[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << array[i] << " "; 
	cout << endl; 
} 

// Main Function to call the other functions
int main() 
{ 
	int array[] = {32,51,21,78,49,12,66}; 
	int size = sizeof(array)/sizeof(array[0]); 
	bubbleSort(array, size); 
	cout<<"The Sorted array: \n"; 
	printArray(array, size); 
	return 0; 
} 



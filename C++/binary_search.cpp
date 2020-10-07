#include <iostream>
using namespace std;

//program to find the location of the integer in the array using cpp

int binarySearch(int array[], int arrLength, int integer) {
    int result = 0;
    int mid;
    int left = 0;
    int right = arrLength;
    while (left <= right && ! result) {
        mid = (left + right) / 2;
        if (array[mid] < integer) {
            left = mid + 1;
        }
        else if (array[mid] > integer) {
            right = mid - 1;
        }
        else {
            result = mid;
        }
    }
    if (! result) {
        result = -1;
    }
    return result;
}

int main() {
    int my_array[10] = {78, 66, 88, 68, 21, 34, 45, 89, 11,99};
    int arrLength = sizeof(my_array) / sizeof(*my_array);
    int find_int = 99;
    cout <<"The position is: " <<binarySearch(my_array, arrLength ,find_int);
}

/*
ID: 22521234
Full Name: Nguyen Thi Xuan Quynh
Session 01 - Exercise 04
Notes or Remarks: ......
*/

#include <iostream>
using namespace std;

// Sorts the array using bubble sort
void Sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if elements are out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Finds the missing number using binary search
int findMissingNumber(int arr[], int n) {
    // Sort the array before searching
    Sort(arr, n);
    int left = 0, right = n - 1;

    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // Return the missing number
    return left;
}

int main() {
    int arr[1000], n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter value: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Output the missing number
    cout << "The missing number is: " << findMissingNumber(arr, n) << endl;
    return 0;
}

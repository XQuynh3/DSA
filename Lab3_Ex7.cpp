/*
ID: 22521234
Full Name: Nguyen Thi Xuan Quynh
Session 01 - Exercise 07
Notes or Remarks: ......
*/

#include <iostream>

// Function to find the minimum element in the array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to count elements <= mid
int countLessOrEqual(int arr[], int n, int mid) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= mid) {
            ++count;
        }
    }
    return count;
}

// Function to find the kth smallest element using a modified binary search
int kthSmallestUsingBinarySearch(int arr[], int n, int k) {
    int low = findMin(arr, n);
    int high = findMax(arr, n);

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessOrEqual(arr, n, mid);

        if (count < k) {
            // Move to the right half
            low = mid + 1;
        } else {
            // Move to the left half
            high = mid;
        }
    }
    return low;  // 'low' now holds the kth smallest element
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;  // Find the 3rd smallest element

    int result = kthSmallestUsingBinarySearch(arr, n, k);
    std::cout << "The " << k << "th smallest element is " << result << std::endl;
    return 0;
}

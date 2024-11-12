#include <iostream>
using namespace std;

// Function to implement bidirectional binary search
int bidirectionalBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int midLeft = left + (right - left) / 2;
        int midRight = right - (right - left) / 2;

        // Check the midLeft point
        if (arr[midLeft] == target) {
            return midLeft;
        }

        // Check the midRight point
        if (arr[midRight] == target) {
            return midRight;
        }

        // Adjust search range based on target comparison
        if (arr[midLeft] < target) {
            left = midLeft + 1;  // Move the left pointer right
        } else {
            right = midLeft - 1;  // Move the right pointer left
        }

        if (arr[midRight] > target) {
            right = midRight - 1;  // Move the right pointer left
        } else {
            left = midRight + 1;  // Move the left pointer right
        }
    }

    // Target not found
    return -1;
}

// Main function to test the algorithm
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    int result = bidirectionalBinarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

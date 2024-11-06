/*
STT: 22521234
Full Name: Nguyen Thi Xuan Quynh
Session 01 - Exercise 01
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;


// find the left index
int bSLeft(int a[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (a[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// find the right index
int bSRight(int a[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

//find the number of occurrences of the value
int countOccurrences(int a[], int n, int value) {
    int leftIndex = bSLeft(a, n, value);
    int rightIndex = bSRight(a, n, value);

    if (leftIndex <= rightIndex) {
        return rightIndex - leftIndex + 1;
    }
    return 0;
}

int main() {
    int a[100], n, value;
    cout << "Number of element: ";
    cin >> n;
    cout << "Enter value: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Enter target value: ";
    cin >> value;
    cout << "The count of occurrences of the target value " << value << " is: " << countOccurrences(a, n, value) << endl;
    return 0;
}

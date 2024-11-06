/*
STT: 22521234
Full Name: Nguyen Thi Xuan Quynh
Session 01 - Exercise 02
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

// Jump Search funct
int jumpSearch(int arr[], int n, int value, int step_size) {
    int prev = 0;
    int curr = 0;

    while (curr < n && arr[curr] < value) {
        prev = curr;
        curr = min(curr + step_size, n - 1);  
    }

    for (int i = prev; i <= curr; i++) {
        if (arr[i] == value) {
            return i;  //if found the target value
        }
    }

    return -1;  // if not found
}

int main() {
    int arr[1000], n, value, step_size;
    cout << "Number of element: ";
    cin >> n;
    cout << "Enter value: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter target value: ";
    cin >> value;

    cout << "Enter step size: ";
    cin >> step_size;

    int result = jumpSearch(arr, n, value, step_size);
    if (result != -1) {
        cout << "The index of the target value is: " << result << endl;
    } else {
        cout << "Cant found." << endl;
    }

    return 0;
}


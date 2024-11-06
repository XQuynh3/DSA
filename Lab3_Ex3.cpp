/*
STT: 22521234
Full Name: Nguyen Thi Xuan Quynh
Session 01 - Exercise 03
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

// Interpolation funct
int interpolationSearch(string arr[], int n, string x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x) {
                return low;
            }
            return -1;
        }

        int pos = low + ((double)(x.compare(arr[low])) * (high - low) / (arr[high].compare(arr[low])));
        if (arr[pos] == x) {
            return pos;
        }

        if (arr[pos].compare(x) < 0)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main()
{
    string arr[1000], target;
    int n;
    cout << "Number of element: ";
    cin >> n;

    cout << "Enter value: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    int index = interpolationSearch(arr, n, target);

    if (index != -1)
        cout << "The index of the target string is: " << index << endl;
    else
        cout << "Not found." << endl;

    return 0;
}


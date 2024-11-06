/*
ID: 22521234
Full Name: Nguyen Thi Xuan Quynh
Session 01 - Exercise 05
Notes or Remarks: ......
*/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int const NMAX = 1e3;
mutex mtx;

//linear search
//number of comparisons of linear search equal its result
void linearSearch(int arr[], int n, int x, int &index, int& comparisons, duration<double>& duration)
{
    auto start = high_resolution_clock::now();
     comparisons = 0;
    for(int i=0; i<n; i++)
    {
        comparisons++;
        if(x == arr[i]) {
//            cout << "Linear Search: The index = "<<i;
            auto end = high_resolution_clock::now();
             duration = end - start;
            index = i;
            return;
        }
    }
    auto end = high_resolution_clock::now();
     duration = end - start;
    index = -1;
}

//binary search
void binarySearch(int arr[], int n, int x, int &index, int& comparisons, duration<double>& duration)
{
    auto start = high_resolution_clock::now();
     comparisons = 0;
    int left=0, right=n-1;
    while(left <= right)
    {
        comparisons++;
        int mid = (left + right)/2;
        if(x == arr[mid]) {
            auto end = high_resolution_clock::now();
            duration = end - start;
            index = mid;
            return;
        }
        if(x<arr[mid]) right = mid-1;
        else left = mid+1;
    }
    auto end = high_resolution_clock::now();
     duration = end - start;
     index = -1;
//    cout << "Binary Search: Not found the element, Comparisons = " << comparisons << ", Duration = " << duration.count() << " seconds" << endl;
}

//jump search
void jumpSearch(int arr[], int n, int x, int &index, int& comparisons, duration<double>& duration)
{
    auto start = high_resolution_clock::now();
     comparisons = 0;
    int step = sqrt(n);
    int tmp = step;
    int prev = 0;
    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += tmp;
        if (prev >= n)
        {
            auto end = high_resolution_clock::now();
             duration = end - start;
             index = -1;
            return;
        }
    }
    for (int i = prev; i < min(step, n); ++i) {
        comparisons++;
        if (arr[i] == x) {
            auto end = high_resolution_clock::now();
             duration = end - start;
             index = i;
            return;
        }
    }
    auto end = high_resolution_clock::now();
    duration = end - start;
    index = -1;
}

int main()
{
    //all search algorithms will return the index of x in array arr[], if not return -1
    int a[]={2,5,7,15,23,34,39,45,46,50,54,67};
    int n = sizeof(a) / sizeof(a[0]);
    int x=25;

    int linearComparisons, binaryComparisons, jumpComparisons;
    int indexLinear, indexBinary, indexJump;
    duration<double> linearDuration, binaryDuration, jumpDuration;

    thread linearThread(linearSearch, (a),n, x, ref(indexLinear), ref(linearComparisons), ref(linearDuration));
    thread binaryThread(binarySearch, (a),n, x, ref(indexBinary),ref(binaryComparisons), ref(binaryDuration));
    thread jumpThread(jumpSearch, (a),n, x, ref(indexJump),ref(jumpComparisons), ref(jumpDuration));

    linearThread.join();
    binaryThread.join();
    jumpThread.join();

    cout << "Linear Search: The index = "<<indexLinear<<", Comparisons = " << linearComparisons << ", Duration = " << linearDuration.count() << " seconds" << endl;
    cout << "Binary Search: The index = "<<indexBinary<<", Comparisons = " << binaryComparisons << ", Duration = " << binaryDuration.count() << " seconds" << endl;
    cout << "Jump Search: The index = "<<indexJump<<", Comparisons = " << jumpComparisons << ", Duration = " << jumpDuration.count() << " seconds" << endl;


    return 0;
}

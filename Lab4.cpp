/*
STT: 22521234
Full Name: Nguyen Thi Xuan Quynh
Exercise 1, 2, 3, 5, 6
Notes or Remarks: ......
*/


// 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// Utility function to generate a vector of random integers
vector<int> generateRandomIntegers(size_t n) {
    vector<int> vec(n);
    generate(vec.begin(), vec.end(), rand);
    return vec;
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        size_t j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to measure execution time
template <typename Func>
auto measureTime(Func func, vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    func(arr);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int main() {
    // Generating 1K random integers
    vector<int> arr = generateRandomIntegers(1000);

    vector<int> bubbleSorted(arr);
    vector<int> insertionSorted(arr);
    vector<int> quickSorted(arr);
    vector<int> mergeSorted(arr);

    auto bubbleTime = measureTime(bubbleSort, bubbleSorted);
    auto insertionTime = measureTime(insertionSort, insertionSorted);
    auto quickTime = measureTime([&](vector<int>& vec) { quickSort(vec, 0, vec.size() - 1); }, quickSorted);
    auto mergeTime = measureTime([&](vector<int>& vec) { mergeSort(vec, 0, vec.size() - 1); }, mergeSorted);

    cout << "Bubble Sort Time: " << bubbleTime << " microseconds\n";
    cout << "Insertion Sort Time: " << insertionTime << " microseconds\n";
    cout << "Quick Sort Time: " << quickTime << " microseconds\n";
    cout << "Merge Sort Time: " << mergeTime << " microseconds\n";

    return 0;
}
// 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>

using namespace std;

// Utility function to generate a vector of random integers
vector<int> generateRandomIntegers(size_t n) {
    vector<int> vec(n);
    generate(vec.begin(), vec.end(), rand);
    return vec;
}

// Sorting functions (same as above, for brevity, not repeated)

// Function to measure execution time
template <typename Func>
auto measureTime(Func func, vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    func(arr);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

void benchmarkSorts(vector<size_t> sizes) {
    for (auto size : sizes) {
        vector<int> arr = generateRandomIntegers(size);

        vector<int> bubbleSorted(arr);
        vector<int> insertionSorted(arr);
        vector<int> quickSorted(arr);
        vector<int> mergeSorted(arr);

        auto bubbleTime = measureTime(bubbleSort, bubbleSorted);
        auto insertionTime = measureTime(insertionSort, insertionSorted);
        auto quickTime = measureTime([&](vector<int>& vec) { quickSort(vec, 0, vec.size() - 1); }, quickSorted);
        auto mergeTime = measureTime([&](vector<int>& vec) { mergeSort(vec, 0, vec.size() - 1); }, mergeSorted);

        cout << "Array Size: " << size << " Elements\n";
        cout << "Bubble Sort Time: " << bubbleTime << " microseconds\n";
        cout << "Insertion Sort Time: " << insertionTime << " microseconds\n";
        cout << "Quick Sort Time: " << quickTime << " microseconds\n";
        cout << "Merge Sort Time: " << mergeTime << " microseconds\n\n";
    }
}

int main() {
    vector<size_t> sizes = {100, 1000, 10000};
    benchmarkSorts(sizes);
    return 0;
}

// 3
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;

// Binary Search to find the insertion position
int binarySearch(const vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item)
            return mid + 1;
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Enhanced Insertion Sort using Binary Search
void binaryInsertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);

        // Shift elements to make space for the key
        for (int j = i - 1; j >= pos; --j) {
            arr[j + 1] = arr[j];
        }
        arr[pos] = key;
    }
}

// Standard Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to measure and compare performance
void compareSorts() {
    const int SIZE = 10000;
    vector<int> arr1(SIZE), arr2(SIZE);

    // Fill the arrays with random values
    srand(time(0));
    for (int i = 0; i < SIZE; ++i) {
        int num = rand() % 100000;
        arr1[i] = num;
        arr2[i] = num;
    }

    // Measure time for Binary Insertion Sort
    auto start = chrono::high_resolution_clock::now();
    binaryInsertionSort(arr1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Binary Insertion Sort Time: " << elapsed.count() << " seconds.\n";

    // Measure time for Standard Insertion Sort
    start = chrono::high_resolution_clock::now();
    insertionSort(arr2);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Standard Insertion Sort Time: " << elapsed.count() << " seconds.\n";
}

int main() {
    compareSorts();
    return 0;
}

//5
#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

// Binary search to find the position to insert 'item'
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Binary Insertion Sort
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);
        for (int j = i - 1; j >= pos; j--)
            arr[j + 1] = arr[j];
        arr[pos] = key;
    }
}

// Normal Insertion Sort
void normalInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int SIZE = 1000;
    int arr1[SIZE], arr2[SIZE];
    srand(time(0));

    // Initialize arrays with random numbers
    for (int i = 0; i < SIZE; i++)
        arr1[i] = arr2[i] = rand() % 10000;

    // Measure time for Normal Insertion Sort
    clock_t start = clock();
    normalInsertionSort(arr1, SIZE);
    clock_t end = clock();
    cout << "Normal Insertion Sort time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

    // Measure time for Binary Insertion Sort
    start = clock();
    binaryInsertionSort(arr2, SIZE);
    end = clock();
    cout << "Binary Insertion Sort time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

    return 0;
}



// 6
#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[]
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to return the maximum value using max heap
int getMaxFromHeap(vector<int>& arr) {
    // Build max heap
    buildMaxHeap(arr);

    // The maximum value will be at the root of the heap
    return arr[0];
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "The maximum value in the array is: " << getMaxFromHeap(arr) << endl;

    return 0;
}




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& arr, int n, int i, bool increasing) {
    int extreme = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    
    if (increasing) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);

        heapify(arr, n, extreme, increasing);
    }
}

void heapSort(vector<int>& arr, bool increasing) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, increasing);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0, increasing);
    }
}

void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << "\n";
}

int main() {
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    cout << "Original Array: ";
    printArray(arr1);

    heapSort(arr1, true);
    cout << "Sorted array (Increasing): ";
    printArray(arr1);

    cout << "-------------------------" << endl;

    vector<int> arr2 = {15, 3, 12, 10, 1, 9};
    cout << "Original Array: ";
    printArray(arr2);

    heapSort(arr2, false);
    cout << "Sorted array (Decreasing): ";
    printArray(arr2);

    return 0;
}

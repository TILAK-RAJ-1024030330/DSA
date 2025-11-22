#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        
        else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
  
    int data[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    int n = sizeof(data)/sizeof (data[0]);
    int target = 23;

    int index = binarySearch(data, n, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    target = 50;
    index = binarySearch(data, n, target);
    if (index == -1) {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int findNumLinearSearch(int arr[], int size, int n) {

    for (int i = 0; i < size; i++) {

        if (arr[i] != i + 1) {
            
            return i + 1;
        }
    }
    return n;
}

int findNumBinarySearch(int arr[], int size, int n) {
    int low = 0;
    int high = size - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] != mid + 1) {
            ans = mid + 1;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    
    int data[] = {1, 2, 4, 5, 6};

    int size = sizeof(data) /sizeof (data[0]);

    int n = 6;

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "Range: 1 to " << n << endl;

    int Num1 = findNumLinearSearch(data, size, n);
    cout << "The number Linear Search is: " << Num1 << endl;

     int Num2 = findNumBinarySearch(data, size, n);
    cout << "The number through Binary Search is: " << Num2 << endl;


    return 0;
}

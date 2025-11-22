#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int swap_count = 0; 

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
            
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count++; 
            }
        }

        if (swap_count == 0) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int data[] = {64, 34, 25, 12, 22, 11, 90};

    int n = sizeof(data)/sizeof (data[0]) ;

    cout << "Original array: ";
    printArray(data, n);

    bubbleSort(data, n);

    cout << "Sorted array:   ";
    printArray(data, n);

    return 0;
}

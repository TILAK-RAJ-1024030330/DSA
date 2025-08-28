#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "\nRow Sums:" << endl;
    for (int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < cols; ++j) {
            rowSum += arr[i][j];
        }
        cout << "Sum of Row " << i << ": " << rowSum << endl;
    }

    cout << "\nColumn Sums:" << endl;
    for (int j = 0; j < cols; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += arr[i][j];
        }
        cout << "Sum of Column " << j << ": " << colSum << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
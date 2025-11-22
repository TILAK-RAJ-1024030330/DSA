#include <iostream>
using namespace std;

int countInversionsBruteForce(int arr[], int n) {
    int inversionCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversionCount++;
            }
        }
    }
    return inversionCount;
}

int main() {
    
    int A[] = {2, 4, 1, 3, 5}; 
    int n = sizeof(A) / sizeof(A[0]);
    
    int total_inversions = countInversionsBruteForce(A, n);

    cout << "The array is: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << (i == n - 1 ? "" : ", ");
    }
    cout << endl;
    cout << "The number of inversions is: " << total_inversions << endl; 
    cout<<endl;

    int B[] = {5, 4, 3, 2, 1}; 
    int n2 = sizeof(B) / sizeof(B[0]);
    int total_inversions2 = countInversionsBruteForce(B, n2);
    
     cout << "The second array is: ";
    for (int i = 0; i < n; i++) {
        cout << B[i] << (i == n - 1 ? "" : ", ");
    }
    cout << endl;
    
    cout << "The number of inversions for the second array is: " << total_inversions2 << endl;

    return 0;
}


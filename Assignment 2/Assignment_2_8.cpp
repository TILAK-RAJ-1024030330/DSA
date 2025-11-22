#include <iostream>

using namespace std;

int countDistinctElements(int arr[], int n) {
    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        
        if (i == j) {
            distinctCount++;
        }
    }

    return distinctCount;
}

int main() {
    int A[] = {30, 50, 30, 10, 20, 40, 10, 20};
    int n = sizeof(A) / sizeof(A[1]);
    
    int distinct_count = countDistinctElements(A, n);

    cout << "The number of distinct elements is: " << distinct_count << endl; 

    int B[] = {1, 1, 1, 1, 1};
    int n2 = sizeof(B) / sizeof(B[1]);
    int distinct_count_b = countDistinctElements(B, n2);
    
    cout << "The number of distinct elements in the second array is: " << distinct_count_b << endl;

    return 0;
}

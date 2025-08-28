#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }

    sort(arr.begin(), arr.end());
    
    int i = 0; 
    for (int j = 1; j < arr.size(); ++j) { 
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    arr.resize(i + 1);
    
    return i + 1; 
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    removeDuplicates(arr);
    
    cout << "Array with unique elements: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

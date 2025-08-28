#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int n = 0;

void create_array();
void display_array();
void insert_element();
void delete_element();
void linear_search();
void show_menu();

int main() {
    int ch;

    do {
        show_menu();
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                create_array();
                break;
            case 2:
                display_array();
                break;
            case 3:
                insert_element();
                break;
            case 4:
                delete_element();
                break;
            case 5:
                linear_search();
                break;
            case 6:
                cout << "Exit program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (ch != 6);
 return 0;
}

void show_menu() {
    cout << "MENU" << endl;
    cout << "1. CREATE" << endl;
    cout << "2. DISPLAY" << endl;
    cout << "3. INSERT" << endl;
    cout << "4. DELETE" << endl;
    cout << "5. LINEAR SEARCH" << endl;
    cout << "6. EXIT" << endl;
}

void create_array() {
    cout << "Enter the number of elements : " << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void display_array() {
    if (n== 0) {
        cout << "Array is empty." << endl;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " " << endl;
    }
}

void insert_element() {

    int pos, value;
    cout << "Enter the position to insert (1 to " << n + 1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position." << endl;
    }

    cout << "Enter the value to insert: ";
    cin >> value;

    for (int i = n; i >= pos; --i) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;
    cout << "Element inserted successfully." << endl;
}

void delete_element() {
    if (n == 0) {
        cout << "Array is empty. Nothing to delete." << endl;
    }

    int pos;
    cout << "Enter the position to delete (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position." << endl;
    }

    for (int i = pos - 1; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    n--;
    cout << "Element deleted successfully." << endl;
}

void linear_search() {
    if (n == 0) {
        cout << "Array is empty. Nothing to search." << endl;
    }

    int key, found_index = -1;
    cout << "Enter the element to search for: ";
    cin >> key;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        cout << "Element found at position: " << found_index + 1 << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}

#include <iostream>
using namespace std;

const int MAX_SIZE = 5; 

int stackArray[MAX_SIZE];
int top = -1; 

bool isEmpty() {
    return top == -1;
}
 
bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int element) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push element." << endl;
    } else {
        top++;
        stackArray[top] = element;
        cout << element << " pushed to stack." << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop element." << endl;
    } else {
        cout << stackArray[top] << " popped from stack." << endl;
        top--;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty. No element to peek." << endl;
    } else {
        cout << "Top element: " << stackArray[top] << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Peek" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) {
                    cout << "Stack is Empty." << endl;
                } else {
                    cout << "Stack is NOT Empty." << endl;
                }
                break;
            case 4:
                if (isFull()) {
                    cout << "Stack is Full." << endl;
                } else {
                    cout << "Stack is NOT Full." << endl;
                }
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void siftUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int n = heap.size();

        if (left < n && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }

        if (right < n && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void insert(int priority) {
        heap.push_back(priority);
        siftUp(heap.size() - 1);
    }

    int extractMax() {
        if (isEmpty()) {
            throw runtime_error("Queue is Empty!");
        }

        int result = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if (!isEmpty()) {
            siftDown(0);
        }

        return result;
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is Empty!");
        }
        return heap[0];
    }
    
    void display() {
        for (int i : heap) cout << i << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    cout << "Inserting 10, 30, 20, 5, 1..." << endl;
    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    pq.insert(5);
    pq.insert(1);
    
    cout << "Current Heap Array: ";
    pq.display(); 

    cout << "Top element (Peek): " << pq.peek() << endl;

    cout << "Extracting Max: " << pq.extractMax() << endl;
    cout << "New Top after extraction: " << pq.peek() << endl;

    cout << "Extracting Max: " << pq.extractMax() << endl;
    
    return 0;
}

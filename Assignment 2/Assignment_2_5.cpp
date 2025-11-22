#include <iostream>
using namespace std;

// (a) Diagonal Matrix
class DiagonalMatrix {
private:
    int n;
    int* data;
public:
    DiagonalMatrix(int size) : n(size) {
        data = new int[n];
        for (int i = 0; i < n; ++i) data[i] = 0;
    }
    ~DiagonalMatrix() { delete[] data; }
    
    void set(int i, int j, int value) {
        
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (i == j) {
                data[i] = value;
            } else if (value != 0) {
                cerr << "Warning: Cannot set non-diagonal element to non-zero value." << endl;
            }
        }
    }

    int get(int i, int j) const {
        
        if (i >= 0 && i < n && j >= 0 && j < n) {
            return (i == j) ? data[i] : 0;
        }
        return 0;
    }

    void display() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (b) Tri-diagonal Matrix
class TriDiagonalMatrix {
private:
    int n;
    int* main_diag; 
    int* super_diag;
    int* sub_diag; 
public:
    TriDiagonalMatrix(int size) : n(size) {
        main_diag = new int[n];
        super_diag = new int[n - 1];
        sub_diag = new int[n - 1];

        for (int i = 0; i < n; ++i) main_diag[i] = 0;
        for (int i = 0; i < n - 1; ++i) {
            super_diag[i] = 0;
            sub_diag[i] = 0;
        }
    }
    
    ~TriDiagonalMatrix() {
        delete[] main_diag;
        delete[] super_diag;
        delete[] sub_diag;
    }

    void set(int i, int j, int value) {
        
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (i == j) {
                main_diag[i] = value;
            } else if (j == i + 1) { 
                super_diag[i] = value;
            } else if (i == j + 1) { 
                sub_diag[j] = value; 
            } else if (value != 0) {
                cerr << "Warning: Setting non-zero value outside tri-diagonal bands." << endl;
            }
        }
    }

    int get(int i, int j) const {
        
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (i == j) {
                return main_diag[i];
            } else if (j == i + 1) {
                return super_diag[i];
            } else if (i == j + 1) {
                return sub_diag[j];
            }
        }
        return 0; 
    }

    void display() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (c) Lower Triangular Matrix
class LowerTriangularMatrix {
private:
    int n;
    int* data;
public:
    LowerTriangularMatrix(int size) : n(size) {
        int total_elements = n * (n + 1) / 2;
        data = new int[total_elements];
        for (int i = 0; i < total_elements; ++i) data[i] = 0;
    }
    ~LowerTriangularMatrix() { delete[] data; }

    int map_to_1D(int i, int j) const {
        
        return i * (i + 1) / 2 + j;
    }

    void set(int i, int j, int value) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (i >= j) {
                data[map_to_1D(i, j)] = value;
            } else if (value != 0) {
                 cerr << "Warning: Cannot set upper triangular element to non-zero value." << endl;
            }
        }
    }

    int get(int i, int j) const {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (i >= j) {
                return data[map_to_1D(i, j)];
            } else {
                return 0;
            }
        }
        return 0; 
    }
    
    void display() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (d) Upper Triangular Matrix
class UpperTriangularMatrix {
private:
    int n;
    int* data;
public:
    UpperTriangularMatrix(int size) : n(size) {
        int total_elements = n * (n + 1) / 2;
        data = new int[total_elements];
        for (int i = 0; i < total_elements; ++i) data[i] = 0;
    }
    
    ~UpperTriangularMatrix() { delete[] data; }

    int map_to_1D(int i, int j) const {
        
        return i * n + j - (i * (i + 1) / 2);
    }

    void set(int i, int j, int value) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (j >= i) { 
                data[map_to_1D(i, j)] = value;
            } else if (value != 0) {
                 cerr << "Warning: Cannot set lower triangular element to non-zero value." << endl;
            }
        }
    }

    int get(int i, int j) const {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (j >= i) {
                return data[map_to_1D(i, j)];
            } else {
                return 0; 
            }
        }
        return 0; 
    }
    
    void display() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (e) Symmetric Matrix
class SymmetricMatrix {
private:
    int n;
    int* data; 
public:
    SymmetricMatrix(int size) : n(size) {
        int total_elements = n * (n + 1) / 2;
        data = new int[total_elements];
        for (int i = 0; i < total_elements; ++i) data[i] = 0;
    }
    ~SymmetricMatrix() { delete[] data; }

    int map_to_1D(int i, int j) const {
        
        return i * (i + 1) / 2 + j;
    }

    void set(int i, int j, int value) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (i >= j) {
                data[map_to_1D(i, j)] = value;
            } else {
                data[map_to_1D(j, i)] = value; 
            }
        }
    }

    int get(int i, int j) const {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (i >= j) {
                return data[map_to_1D(i, j)];
            } else {
                return data[map_to_1D(j, i)];
            }
        }
        return 0; 
    }

    void display() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    cout << "Diagonal Matrix (4x4)" << endl;
    DiagonalMatrix dm(4);
    dm.set(0, 0, 10); dm.set(1, 1, 20); dm.set(2, 2, 30); dm.set(3, 3, 40);
    dm.display();
    
     cout << "\nTri-diagonal Matrix (5x5)" << endl;
    TriDiagonalMatrix tdm(5);
    for (int i = 0; i < 5; ++i) {
        tdm.set(i, i, (i + 1) * 10); 
    }
    for (int i = 0; i < 4; ++i) {
        tdm.set(i, i + 1, i + 1);    
        tdm.set(i + 1, i, -(i + 1)); 
    }
    
    tdm.display();
    
    cout << "\nLower Triangular Matrix (4x4)" << std::endl;
    LowerTriangularMatrix ltm(4);
    ltm.set(0, 0, 1); ltm.set(1, 0, 2); ltm.set(1, 1, 3);
    ltm.set(2, 0, 4); ltm.set(2, 1, 5); ltm.set(2, 2, 6);
    ltm.set(3, 0, 7); ltm.set(3, 1, 8); ltm.set(3, 2, 9); ltm.set(3, 3, 10);
    ltm.display();
    
    cout << "\nUpper Triangular Matrix (4x4)" <<endl;
    UpperTriangularMatrix utm(4);
    utm.set(0, 0, 1); utm.set(0, 1, 2); utm.set(0, 2, 3); utm.set(0, 3, 4);
    utm.set(1, 1, 5); utm.set(1, 2, 6); utm.set(1, 3, 7);
    utm.set(2, 2, 8); utm.set(2, 3, 9);
    utm.set(3, 3, 10);
    utm.display();
    
    cout << "\nSymmetric Matrix (4x4)" << endl;
    SymmetricMatrix sm(4);
    sm.set(0, 0, 1); 
    sm.set(1, 0, 2); sm.set(1, 1, 5); 
    sm.set(2, 1, 6); sm.set(2, 2, 8);
    sm.set(3, 2, 9); sm.set(3, 3, 10);
    sm.display();

    return 0;
}


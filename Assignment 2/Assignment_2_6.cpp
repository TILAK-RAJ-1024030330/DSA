#include <iostream>
using namespace std;

const int MAX_TERMS = 100;

class Term {
public:
    int row;
    int col;
    int val;
};

class SparseMatrix {
private:
    Term data[MAX_TERMS];
    int numRows;
    int numCols;
    int numTerms;

public:
    SparseMatrix() : numRows(0), numCols(0), numTerms(0) {}

    void initialize(int rows, int cols, int termsCount, Term terms[]) {
        numRows = rows;
        numCols = cols;
        numTerms = termsCount;
        for (int i = 0; i < numTerms; ++i) {
            data[i + 1] = terms[i];
        }
    }

    SparseMatrix transpose() const {
        SparseMatrix b;
        b.numRows = numCols;
        b.numCols = numRows;
        b.numTerms = numTerms;

        if (numTerms > 0) {
            int currentBIndex = 1;
            for (int j = 0; j < numCols; j++) {
                for (int i = 1; i <= numTerms; i++) {
                    if (data[i].col == j) {
                        b.data[currentBIndex].row = data[i].col;
                        b.data[currentBIndex].col = data[i].row;
                        b.data[currentBIndex].val = data[i].val;
                        currentBIndex++;
                    }
                }
            }
        }
        return b;
    }

    SparseMatrix add(const SparseMatrix& b) const {
        SparseMatrix c;
        if (numRows != b.numRows || numCols != b.numCols) {
            cout << "Error: Matrices have different dimensions, cannot add." << endl;
            c.numTerms = 0;
            return c;
        }

        int i = 1, j = 1, k = 1;
        int termsA = numTerms, termsB = b.numTerms;

        while (i <= termsA && j <= termsB) {
            if (data[i].row < b.data[j].row || (data[i].row == b.data[j].row && data[i].col < b.data[j].col)) {
                c.data[k++] = data[i++];
            } else if (b.data[j].row < data[i].row || (b.data[j].row == data[i].row && b.data[j].col < data[i].col)) {
                c.data[k++] = b.data[j++];
            } else {
                c.data[k].row = data[i].row;
                c.data[k].col = data[i].col;
                c.data[k].val = data[i].val + b.data[j].val;
                if (c.data[k].val != 0) { k++; }
                i++; j++;
            }
        }

        while (i <= termsA) { c.data[k++] = data[i++]; }
        while (j <= termsB) { c.data[k++] = b.data[j++]; }

        c.numRows = numRows;
        c.numCols = numCols;
        c.numTerms = k - 1;
        return c;
    }

    SparseMatrix multiply(const SparseMatrix& b) const {
        SparseMatrix c;
        if (numCols != b.numRows) {
            cout << "Error: Matrices dimensions are incompatible for multiplication." << endl;
            c.numTerms = 0;
            return c;
        }

        SparseMatrix bT = b.transpose();
        int i = 1, k = 1;
        int termsA = numTerms, termsBT = bT.numTerms;

        c.numRows = numRows;
        c.numCols = b.numCols;

        for (i = 1; i <= termsA; ) {
            int currentRowA = data[i].row;
            for (int j = 1; j <= termsBT; ) {
                int currentRowBT = bT.data[j].row;
                int sum = 0;
                int tempI = i, tempJ = j;

                while (tempI <= termsA && data[tempI].row == currentRowA &&
                       tempJ <= termsBT && bT.data[tempJ].row == currentRowBT) {
                    if (data[tempI].col < bT.data[tempJ].col) {
                        tempI++;
                    } else if (data[tempI].col > bT.data[tempJ].col) {
                        tempJ++;
                    } else {
                        sum += data[tempI].val * bT.data[tempJ].val;
                        tempI++;
                        tempJ++;
                    }
                }

                if (sum != 0) {
                    c.data[k].row = currentRowA;
                    c.data[k].col = currentRowBT;
                    c.data[k].val = sum;
                    k++;
                }
                while (j <= termsBT && bT.data[j].row == currentRowBT) { j++; }
            }
            while (i <= termsA && data[i].row == currentRowA) { i++; }
        }
        c.numTerms = k - 1;
        return c;
    }

    void print() const {
        if (numTerms == 0) {
            cout << "Matrix is empty or operation failed." << endl;
            return;
        }
        cout << "\nSparse Matrix (Triplet form):" << endl;
        cout << "Original Dimensions: " << numRows << "x" << numCols << ", Non-zero Terms: " << numTerms << endl;
        cout << "Row\tCol\tValue" << endl;
        for (int i = 1; i <= numTerms; i++) {
            cout << data[i].row << "\t" << data[i].col << "\t" << data[i].val << endl;
        }
    }
};

int main() {
    
    Term termsA[] = {
        {0, 0, 3},
        {1, 1, 5},
        {2, 2, 7}
    };
    Term termsB[] = {
        {0, 0, 1},
        {1, 1, 2},
        {2, 2, 3}
    };

    SparseMatrix A, B;
    A.initialize(3, 3, 3, termsA);
    B.initialize(3, 3, 3, termsB);

    cout << "Matrix A:";
    A.print();
    cout << "\nMatrix B:";
    B.print();

    SparseMatrix TransposedA = A.transpose();
    cout << "\nTranspose of A";
    TransposedA.print();

    SparseMatrix Sum = A.add(B);
    cout << "\nAddition of A + B";
    Sum.print();

    SparseMatrix Product = A.multiply(B);
    cout << "\nMultiplication of A * B";
    Product.print();

    return 0;
}


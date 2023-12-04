#include <iostream>

#include "./include/matrix.hpp"

using namespace std;

const int MAX = 10e4 + 10;

// Definition of matrices
matrix leaf[MAX];
matrix segTree[4 * MAX];
matrix def;

/**
 * @brief Matrix multiplication function with modulo operation
 * 
 * @param a Matrix operand
 * @param b Matrix operand
 * @return Result of matrix multiplication with modulo applied
 */
matrix mult(matrix a, matrix b) {
    matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
            result.m[i][j] %= 100000000;  // Applying modulo to avoid overflow
        }
    }
    return result;
}

/**
 * @brief Recursive function to query the segment tree
 * 
 * @param a Start index of the query range
 * @param b End index of the query range
 * @param p Current position in the segment tree
 * @param l Left boundary of the current segment
 * @param r Right boundary of the current segment
 * @return Result of the query operation
 */
matrix query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return def;
    if (a <= l && r <= b) return segTree[p];
    int m = (l + r) / 2;
    return mult(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

/**
 * @brief Recursive function to update a matrix in the segment tree
 * 
 * @param i Index of the matrix to be updated
 * @param x New matrix value
 * @param p Current position in the segment tree
 * @param l Left boundary of the current segment
 * @param r Right boundary of the current segment
 * @return Updated matrix in the segment tree
 */
matrix update(int i, matrix x, int p, int l, int r) {
    if (i < l || r < i) return segTree[p];
    if (l == r) return segTree[p] = x;
    int m = (l + r) / 2;
    return segTree[p] = mult(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}

/**
 * @brief Function to print a matrix
 * 
 * @param result Matrix to be printed
 */
void print(matrix result) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            cout << result.m[i][j] << ' ';
        }
    }
    cout << endl;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        char op; cin >> op;
        matrix novaM; matrix point; matrix result;

        switch (op) {
        case 'u':
            int p; cin >> p;
            cin >> novaM.m[0][0] >> novaM.m[0][1] >> novaM.m[1][0] >> novaM.m[1][1];
            leaf[p] = novaM;
            update(p, novaM, 1, 0, n - 1);
            break;
        case 'q':
            int b, d;
            cin >> b >> d;
            cin >> point.m[0][0] >> point.m[1][0];
            point.m[0][1] = 0;
            point.m[1][1] = 0;
            result = mult(query(b, d, 1, 0, n - 1), point);
            print(result);
            break;
        default:
            cout << "Invalid Operation" << endl;
            break;
        }
    }
}

#include <iostream>

#include "matrix.hpp"
#include "../include/memlog.hpp"

using namespace std;

const int MAX = 10e5 + 10;

// Definition of matrices
matrix leaf[MAX];
matrix segTree[4 * MAX];
matrix def;

// Matrix multiplication function with modulo operation
matrix mult(matrix a, matrix b) {
    matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
                LEMEMLOG((long int)(&(a.m[i][k])), sizeof(double), a.m[i][k]);
                LEMEMLOG((long int)(&(b.m[k][j])), sizeof(double), b.m[k][j]);
                ESCREVEMEMLOG((long int)(&(result.m[i][j])), sizeof(double), result.m[i][j]);
            }
            result.m[i][j] %= 100000000;  // Applying modulo to avoid overflow
        }
    }
    return result;
}

// Recursive function to build the segment tree
matrix build(int p, int l, int r) {
    if (l == r) return segTree[p] = leaf[l];
    int m = (l + r) / 2;
    return segTree[p] = mult(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}

// Recursive function to query the segment tree
matrix query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return def;
    if (a <= l && r <= b) return segTree[p];
    int m = (l + r) / 2;
    return mult(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

// Recursive function to update a matrix in the segment tree
matrix update(int i, matrix x, int p, int l, int r) {
    if (i < l || r < i) return segTree[p];
    if (l == r) return segTree[p] = x;
    int m = (l + r) / 2;
    return segTree[p] = mult(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}

// Function to print a matrix
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

    char lognome[100] = "/tmp/matrix.out";
    int regmem = 1;

    iniciaMemLog(lognome);

    if(regmem) ativaMemLog();
    else desativaMemLog();

    defineFaseMemLog(0);

    for (int i = 0; i < q; i++) {
        char op; cin >> op;
        matrix novaM; matrix point; matrix result;

        switch (op) {
        case 'u':
            defineFaseMemLog(0);
            int p; cin >> p;
            cin >> novaM.m[0][0] >> novaM.m[0][1] >> novaM.m[1][0] >> novaM.m[1][1];
            leaf[p] = novaM;
            update(p, novaM, 1, 0, n - 1);
            break;
        case 'q':
            defineFaseMemLog(0);
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

#include <iostream>
#include "matrix.hpp"

using namespace std;

const int MAX = 10e5+10;

matrix v[MAX];
matrix seg[4*MAX];
matrix def;

matrix mult(matrix a, matrix b){
    matrix result; 
    
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) { 
            result.m[i][j] = 0; 

            for (int k = 0; k < 2; k++) { 
                result.m[i][j] += a.m[i][k] * b.m[k][j]; 
            } 
   
        } 
    } 

    return result;
}

matrix build(int p, int l, int r){
    if(l == r) return seg[p] = v[l];
    int m = (l + r)/2;
    return seg[p] = mult(build(2*p, 1, m), build(2*p+1, m+1, r));
}

matrix query(int a, int b, int p, int l, int r){
    if(b < 1 || r<a) return def;
    if(a <= 1 && r <= b) return seg[p];
    int m = (l+r)/2;
    return mult(query(a, b, (2*p), 1, m), query(a, b, 2*p+1, m+1, r));
}

matrix update(int i, matrix x, int p, int l, int r){
    if(i<l || r < i) return seg[p];
    if(l == r) return seg[p] = x;
    int m =(l+r)/2;
    return seg[p] = mult(update(i, x, 2*p, 1, m), update(i, x, 2*p+1, m+1, r));
}

void print(matrix result){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1; j++){
            cout << result.m[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int n, q; cin >> n >> q;
    for (int i = 0; i < q; i++){
        char op; cin >> op;
        matrix novaM;
        matrix point;
        matrix result; 
        switch (op){
            case 'u':
                int p; cin >> p;
                cin >> novaM.m[0][0] >> novaM.m[0][1] >> novaM.m[1][0] >> novaM.m[1][1];
                v[p] = novaM; update(p, novaM, 1, 0, n-1);
                cout << "UPDATE" << endl;
                break;
            case 'q':
                int b, d; cin >> b >> d;
                cin >> point.m[0][0] >> point.m[1][0];
                point.m[0][1] = 0; point.m[1][1] = 0;
                result = mult(query(b, d, 1, 0, n-1), point);
                print(result);
                cout << "falho" << endl;
                break;
            default:
                cout << "Operação Inválida" << endl;
                break;
        }
        cout << "LEU" << endl;
    }
    
}
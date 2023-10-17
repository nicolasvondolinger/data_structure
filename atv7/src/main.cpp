#include <iostream>
#include "heap.hpp"

using namespace std;

int main (){

    int n; cin >> n;
    Heap h(n);
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        h.Inserir(num);
    }

    for(int i = 0; i < n; i++){
        cout << h.Remover() << " ";
    }

    return 0;
}
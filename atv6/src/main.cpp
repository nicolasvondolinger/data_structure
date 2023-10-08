#include <iostream>
#include "../include/graph.hpp"

using namespace std;

int main(){

    Grafo componente;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int q; cin >> q;
        for(int j = 0; j < q; j++){
            int c; cin >> c;
            componente.InsereAresta(j, c);
        }
    }
    

    return 0;
}
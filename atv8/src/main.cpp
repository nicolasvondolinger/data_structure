#include <iostream>
#include "unionFind.hpp"
#include "heap.hpp"

using namespace std;

int main (){

    int n, m; cin >> n >> m;
    UnionFind tree(n);
    Heap arestas(m);
    for(int i = 0; i < m; i++){
        int v1, v2, c; cin >> v1 >> v2 >> c;
        Aresta a;
        a.u = v1; a.v = v2; a.custo = c;
        arestas.Inserir(a);
    }

    for(int i = 0; i < n; i++){
        tree.Make(i); 
    }

    int custo = 0;
    for(int i = 0; i < m; i++){
        Aresta a = arestas.Remover();
        int a1 = tree.Find(a.u); int a2 = tree.Find(a.v);
        tree.Union(a.u, a.v);
        if(a1 != tree.Find(a.u) || a2 != tree.Find(a.v)) custo += a.custo;
    }

    cout << custo << endl;

    return 0;
}
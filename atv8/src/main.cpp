#include <iostream>
#include "unionFind.hpp"
#include "heap.hpp"

using namespace std;

int main (){

    int n, m; cin >> n >> m;
    UnionFind unionFind(n);
    Heap arestas(n);
    for(int i = 0; i < m; i++){
        int v1, v2, c; cin >> v1 >> v2 >> c;
        Aresta a;
        a.u = v1; a.v = v2; a.custo = c;
        unionFind.Make(i); arestas.Inserir(a);
    }

    int custo = 0;
    for(int i = 0; i < m; i++){
        int a1 = unionFind.Find(a.u), int a2 = unionFind.Find(a.v);
        Aresta a = Heap.Remover();
        unionFind.Union(a.u, a.v);
        if(a1)
    }

    
    cout >> custo >> endl;

    return 0;
}
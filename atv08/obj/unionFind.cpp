#include <iostream>
#include "../include/unionFind.hpp"
#include "../include/heap.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos){
    tamanho = quantidade_subconjuntos;
    subconjuntos = new Subconjunto[tamanho];
    
}

UnionFind::~UnionFind(){
    delete[] subconjuntos;
}

void UnionFind::Make(int x){
    subconjuntos[x].representante = x;
    subconjuntos[x].rank = 1;
}

int UnionFind::Find(int x){
    if(subconjuntos[x].representante == x) return x;
    else Find(subconjuntos[x].representante);
}

void UnionFind::Union(int x, int y){
    int xrep = find(x);
    int yrep = find(y);
    if(xrep == yrep) return;
    if(subconjuntos[xrep].rank < subconjuntos[yrep].rank){
        subconjuntos[xrep].representante = yrep;    
    } else if (subconjuntos[xrep].rank > subconjuntos[yrep].rank){
        subconjuntos[yrep].representante = xrep;
    } else {
        subconjuntos[yrep].representante = xrep;
        subconjuntos[xrep].rank++;
    }
}
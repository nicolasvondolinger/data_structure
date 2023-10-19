#include <iostream>
#include "unionFind.hpp"
#include "heap.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos){
    tamanho = quantidade_subconjuntos;
    subconjuntos = new Subconjunto[tamanho];
}

UnionFind::~UnionFind(){
    delete[] subconjuntos;
}

void UnionFind::Make(int x){
    subconjuntos[x].representante = x;
}

int UnionFind::Find(int x){
    return subconjuntos[x].representante;
}

void UnionFind::Union(int x, int y){
    if(subconjuntos[x].representante == subconjuntos[y].representante) return;
    subconjuntos[y].representante = x;
}
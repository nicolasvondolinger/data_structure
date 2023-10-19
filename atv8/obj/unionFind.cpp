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
    
}

int UnionFind::Find(int x){
    
}

void UnionFind::Union(int x, int y){
    subconjuntos[x].representante = 0;
    subconjuntos[y].representante = 0;
    
}
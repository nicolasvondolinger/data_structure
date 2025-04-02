#include <iostream>
#include <getopt.h>
#include "../include/graph.hpp"

using namespace std;

int main(int argc, char* argv[]){
    int opt;
    Grafo componente;

    int n; cin >> n;
    for(int i = 0; i <n; i++){
        componente.InsereVertice(i);
    }
    for (int i = 0; i < n; i++){
        int q; cin >> q;
        for(int j = 0; j < q; j++){
            int c; cin >> c;
            componente.InsereAresta(i, c);
        }
    }

    while ((opt = getopt(argc, argv, "dnk")) != -1) {
        switch (opt) {
            case 'd':
                cout << componente.QuantidadeVertices() << endl;
                cout << componente.QuantidadeArestas() << endl;
                cout << componente.GrauMinimo() << endl ;
                cout << componente.GrauMaximo() << endl;
                break;
            case 'n':
                componente.ImprimeVizinhos();
                break;
            case 'k':
                cout << ((componente.GrauMaximo() == componente.GrauMinimo()) && (componente.GrauMaximo() == componente.QuantidadeVertices() - 1)) << endl;
                break;
            default:
                return 1;
        }
    }
    
    return 0;
}
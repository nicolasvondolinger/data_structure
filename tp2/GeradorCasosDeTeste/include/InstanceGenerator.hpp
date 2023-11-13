#ifndef INSTANCE_GENERATOR_HPP
#define INSTANCE_GENERATOR_HPP

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> ColorList;

typedef struct s_ins{
    char orderingMethod;
    int vertexCount;
    string adjacency;
    ColorList vertexColors;
    
    bool isYes;
    bool isRandom;
    vector<int> permutation;

    int largestColorUsed;

    string toString();
} Instance;

class InstanceGenerator{
    public:
        InstanceGenerator();
        ~InstanceGenerator();

        /*  Gera uma instancia aleatoria com a quantidade de vertices e arestas
         * indicadas.
         */
        string NewInstance(int vertices, int edges);

        /* Gera uma instancia com a quantidade de vertices e arestas indicadas.
         * A resposta depende da booleana isYes. Caso esta variavel seja falsa, 
         * ira modificar as cores de até n vértices. Note que ainda existe uma
         * chance da instancia ser sim, especialmente em grafos pequenos.
         */
        string NewInstance(int vertices, int edges, bool isYes);

        /* Gera uma instancia com a quantidade de vertices e arestas indicadas.
         * A variavel errorCount indica a quantidade de vertices que terao 
         * suas cores sorteadas. Note que isso nao garante que a instancia 
         * sera uma instancia "nao", especialmente se o grafo for pequeno e
         * errorCount for grande.
         */
        string NewInstance(int vertices, int edges, int errorCount);

    private:
        
        int n;
        int m;
        int** adjacency;

        Instance GenerateYesInstance();
        Instance GenerateNoInstance(int incorrectCount);
        Instance GenerateRandomInstance();

        Instance GenerateNewInstance(int vertices, int edges);
        Instance GenerateNewInstance(int vertices, int edges, bool isYes);
        Instance GenerateNewInstance(int vertices, int edges, int errorCount);

        char GetOrderingMethod();
        
        void CreateAdjacency();
        void DestroyAdjacency();
        string GetAdjacencyString();
};

#endif
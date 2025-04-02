#include <bits/stdc++.h>
#include "../include/InstanceGenerator.hpp"
#include "../include/Random.hpp"
#include "../include/Utils.hpp"

#define MAX_VERTICES 9999
#define MAX_EDGES 49985001

using namespace std;

string Instance::toString(){
    string s(1, orderingMethod);
    s += " " + to_string(vertexCount) + "\n";
    s += adjacency;
    for(int i = 0; i < vertexColors.size(); i++){
        s += to_string(vertexColors[i]) + " ";
    }
    s += "\n";
    return s;
}

InstanceGenerator::InstanceGenerator(){}

InstanceGenerator::~InstanceGenerator(){}

string InstanceGenerator::NewInstance(int vertices, int edges){
    return GenerateNewInstance(vertices, edges).toString();
}

string InstanceGenerator::NewInstance(int vertices, int edges, bool isYes){
    return GenerateNewInstance(vertices, edges, isYes).toString();
}

string InstanceGenerator::NewInstance(int vertices, int edges, int errorCount){
    return GenerateNewInstance(vertices, edges, errorCount).toString();
}

Instance InstanceGenerator::GenerateNewInstance(int vertices, int edges){
    n = min(vertices, MAX_VERTICES);
    m = (n*(n-1))/2;
    m = min(edges, m);
    Instance i = GenerateRandomInstance();
    DestroyAdjacency();
    return i;
}

Instance InstanceGenerator::GenerateNewInstance(int vertices, int edges, bool isYes){
    n = min(vertices, MAX_VERTICES);
    m = (n*(n-1))/2;
    m = min(edges, m);
    Instance i = (isYes) ? GenerateYesInstance() : GenerateNoInstance(Random::Int(n));
    DestroyAdjacency();
    return i;
}

Instance InstanceGenerator::GenerateNewInstance(int vertices, int edges, int errorCount){
    n = min(vertices, MAX_VERTICES);
    m = (n*(n-1))/2;
    m = min(edges, m);
    errorCount = min(errorCount, n);
    Instance i = GenerateNoInstance(errorCount);
    DestroyAdjacency();
    return i;
}

Instance InstanceGenerator::GenerateYesInstance(){
    Instance s;
    s.vertexCount = n;
    s.isYes = true;
    s.isRandom = false;
    s.orderingMethod = GetOrderingMethod();
    s.largestColorUsed = 0;

    CreateAdjacency();
    s.adjacency = GetAdjacencyString();
    
    s.permutation = Random::Permutation(n);
    ColorList colors(n, 0);
    
    for(int i = 0; i < n; i++){
        int v = s.permutation[i];
        ColorList availableColors(n+1, 1);
        availableColors[0] = 0;
        for(int j = 0; j < n; j++){
            if(adjacency[v][j]){
                availableColors[colors[j]] = 0;
            }
        }
        int k = 1;
        while(availableColors[k] == 0) k++;

        colors[v] = k;
        s.largestColorUsed = max(s.largestColorUsed, k);
    }

    s.vertexColors = colors;

    return s;
}

Instance InstanceGenerator::GenerateNoInstance(int incorrectCount){
    Instance s = GenerateYesInstance();
    s.isYes = false;
    
    vector<int> V(n, 0);
    for(int i = 0; i < n; i++){
        V[i] = i;
    }

    while(incorrectCount > 0){
        int u = Random::Int(V.size());
        ColorList availableColors(n, 1);
        for(int i = 0; i < availableColors.size(); i++){
            availableColors[i] = i+1;
        }

        for(int j = 0; j < n; j++){
            if(adjacency[u][j]){
                int pos = Utils::BinarySearch(availableColors, s.vertexColors[j]);
                if(pos >= 0) availableColors.erase(availableColors.begin() + pos);
            }
        }

        int c = availableColors[Random::Int(availableColors.size())];
        s.vertexColors[u] = c;
        s.largestColorUsed = max(s.largestColorUsed, c);
        incorrectCount--;
    }

    return s;
}

Instance InstanceGenerator::GenerateRandomInstance(){
    Instance s;
    s.vertexCount = n;
    s.isYes = false;
    s.isRandom = true;
    s.orderingMethod = GetOrderingMethod();
    s.largestColorUsed = 0;

    CreateAdjacency();
    s.adjacency = GetAdjacencyString();
    
    s.permutation = Random::Permutation(n);
    ColorList colors(n, 0);

    for(int i = 0; i < n; i++){
        int v = s.permutation[i];
        ColorList availableColors;
        for(int j = 0; j < n; j++){
            availableColors.push_back(j+1);
        }
        
        for(int j = 0; j < n; j++){
            if(adjacency[v][j]){
                int pos = Utils::BinarySearch(availableColors, colors[j]);
                if(pos >= 0) availableColors.erase(availableColors.begin() + pos);
            }
        }
        
        int k = availableColors[Random::Int(availableColors.size())];
        colors[v] = k;
        s.largestColorUsed = max(s.largestColorUsed, k);
    }
    s.vertexColors = colors;

    return s;
}

char InstanceGenerator::GetOrderingMethod(){
    int m = Random::Int(7);
    switch(m){
        case 0: return 'b';
        case 1: return 's';
        case 2: return 'i';
        case 3: return 'q';
        case 4: return 'm';
        case 5: return 'p';
        default:return 'y';
    }
}

void InstanceGenerator::CreateAdjacency(){
    int edgeCount = 0;
    
    adjacency = new int* [n];
    for(int i = 0; i < n; i++){
        adjacency[i] = new int[n];
        for(int j = 0; j < n; j++){
            adjacency[i][j] = 0;
        }
    }
    
    while (edgeCount < m){
        int u = Random::Int(n);
        int v = Random::Int(n);
        if(u != v && adjacency[u][v] == 0){
            adjacency[u][v] = 1;
            adjacency[v][u] = 1;
            edgeCount++;
        }
    }
}

void InstanceGenerator::DestroyAdjacency(){
    for(int i = 0; i < n; i++){
        delete[] adjacency[i];
    }
    delete[] adjacency;
} 

string InstanceGenerator::GetAdjacencyString(){
    string s = "";
    for(int i = 0; i < n; i++){
        string v = " ";
        int neighboors = 0;
        
        for(int j = 0; j < n; j++){
            if(adjacency[i][j]){
                v += to_string(j) + " ";
                neighboors++;
            }
        }

        s += to_string(neighboors) + v + "\n";
    }
    return s;
}
#include <bits/stdc++.h>
#include "../include/Random.hpp"

using namespace std;

void Random::SetSeed(){
    srand(time(0));
}

double Random::Double(){
    return rand() / (double)RAND_MAX;
}

int Random::Int(int max){
    return rand() % (max);
}

vector<int> Random::Permutation(int n)
{
    int index, num;
    vector<int> v, s;
 
    for (int i = 0; i < n; i++)
        v.push_back(i);
 
    while (v.size()) {
        n = v.size();
        index = Int(n);
        num = v[index];
        swap(v[index], v[n - 1]);
        v.pop_back();
        s.push_back(num);
    }

    return s;
}
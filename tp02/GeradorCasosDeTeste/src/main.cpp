#include <bits/stdc++.h>
#include "../include/InstanceGenerator.hpp"
#include "../include/Random.hpp"
#include "../include/Utils.hpp"

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    Random::SetSeed();
    InstanceGenerator* ig = new InstanceGenerator();
    // Altere aqui os atributos da instancia que deseja criar
    cout << ig->NewInstance(n, m, true);
    delete ig;
}
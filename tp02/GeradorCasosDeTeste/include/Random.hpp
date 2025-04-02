#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <bits/stdc++.h>

using namespace std;

class Random{
    public:
        static constexpr double Espilon = 10e-8;

        static void SetSeed();
        static double Double();
        static int Int(int max);
        static vector<int> Permutation(int n);

};

#endif
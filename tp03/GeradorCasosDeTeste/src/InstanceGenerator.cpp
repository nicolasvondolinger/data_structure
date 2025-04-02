#include <bits/stdc++.h>
#include "../include/InstanceGenerator.hpp"
#include "../include/Random.hpp"

using namespace std;

#define MAX_K 1000

string InstanceGenerator::GetInstance(int array_size, int query_count){
    string s = to_string(array_size) + " " + to_string(query_count) + "\n";

    for(int i = 0; i < query_count; i++)  {
        int q = Random::Int(2);
        
        if(q == 0){
            int pos = Random::Int(array_size);
            s += "u " + to_string(pos) +"\n";
            for(int j = 0; j < 2; j++)  {
                for(int q = 0; q < 2; q++)  {
                    int k = Random::Int(MAX_K);
                    s += to_string(k) + " "; 
                }
                s+= "\n";
            }
        }

        else{
            int l, r, x, y;
            l = Random::Int(array_size);
            r = Random::Int(array_size);

            x = Random::Int(MAX_K);
            y = Random::Int(MAX_K);

            s += "q " + to_string(min(l,r)) + " " + to_string(max(l,r)) + " " + to_string(x) + " " + to_string(y) + "\n";
        }
    }

    return s;
}
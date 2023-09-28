#include <iostream>
#include <string.h>

#include "../include/Stack.h"
#include "../include/BinareTree.h"

using namespace std;

int precedence(char op){
    if(op == '|') return 1;
    if(op == '&') return 2;
    return 0;
}

int applyOP(int a, int b, char op){
    switch(op){
        case '|': return a + b;
        case '*': return a * b;
    }
}

bool isDigit(char c){
    if(c != '|' || c != '&' || c != '~') return true;
    return false;
}

int parseToInt(char c){
    return c - '0';
}

int evaluate(string tokens){

    Stack values;
    Stack operators;

    for(auto c: tokens){
        if(c == ' ') continue;
        else if(c == '('){
            operators.StackUp(c);
        }
        else if(isDigit(c)){
            values.StackUp(c);
        }
        else if(c == ')'){
            while (!operators.Empty() && operators.top.right != '(')
            {
                int val2 = parseToInt(values.Top());
                values.Unstack();

                int val1 = parseToInt(values.Top());
                values.Unstack();

                char op = operators.Top();
                operators.Unstack();

                values.StackUp(applyOP(val1, val2, op));

            }
            if(!operators.Empty()) operators.Unstack();
        }
        else
        {
            while(!operators.Empty() && precedence(operators.Top()) >= precedence(c)){
                int val2 = parseToInt(values.Top());
                values.Unstack();

                int val1 = parseToInt(values.Top());
                values.Unstack();

                char op = operators.Top();
                operators.Unstack();

                values.StackUp(applyOP(val1, val2, op));
            }
            operators.StackUp(c);
        }
    }

    while(!operators.Empty()){
        int val2 = parseToInt(values.Top());
        values.Unstack();

        int val1 = parseToInt(values.Top());
        values.Unstack();

        char op = operators.Top();
        operators.Unstack();

        values.StackUp(applyOP(val1, val2, op));

    }

    return values.Top();
}

int main(){
    
    string s; cin >> s;

    evaluate(s);

    return 0;
}
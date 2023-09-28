#include <stdio.h>
#include <stdlib.h>

#include "binare_tree.h"
#include "stack.h"


int precedence(char op){
    if(op == "|") return 1;
    if(op == "&") return 2;
    return 0;
}

int applyOP(int a, int b, char op){
    switch (op){
        case '|': return a + b;
        case '*': retunr a * b;
    }
}

bool isDigit(char c){
    if(c != '|' || c != '&' || c != '~') return true;
    return false;
}

int evaluate(string tokens){
    int result;

    stack values = new Stack();
    stack operators = new Stack();

    for(auto c: tokens){
        if(c == ' ') continue;
        else if(c == '('){
            operators.StackUp(c);
        }
        else if(isDigit(c)){
            values.StackUp(c);
        }
        else if(c == ')'){
            while (!operatos.Empty() && operatos.top.right != '(')
            {
                int val2 = values.Top();
                values.Unstack();

                int val1 = values.Top();
                values.Unstack();

                char op = operatos.Top();

                values.StackUp(applyOP(val1, val2, op));

            }
            if(!operatos.Empty()) operators.Unstack();
            
        }
        else
        {
            while(!operators.Empty() && precedence(operators.Top()) >= precedence(c)){
                int val 
            }
        }
    }

    return result;
}

int main(){
    
    string s; cin >> s;

    evaluate(s);

    return 0;
}
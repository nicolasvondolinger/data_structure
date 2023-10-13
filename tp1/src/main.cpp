#include <iostream>
#include <string.h>
#include <getopt.h>
#include "../include/Stack.h"
#include "../include/BinaryTree.h"

using namespace std;

#define EVALUATE 1
#define SATISFACTION 2

string tokens, valuation;

int precedence(char op){
    switch (op){
        case '|':
            return 1;
        case '&':
            return 2;
        case '~':
            return 3;
        default:
            return 0;
    }
}

int applyOP(int a, int b, char op){
    if(a == 1 && b == 1 && op == '|') return a;
    switch(op){
        case '|': 
            if(a == 1 && b == 1) return a;
            else return a+b;
        case '&': return a * b;
        default: throw std::runtime_error("Invalid Operator");
    }
}

char applyNeg(char a){
    switch(a){
        case '0': return '1';
        case '1': return '0';
        default: throw std::runtime_error("Invalid Value");
    }
}

bool isDigit(char c){
    return (c >= '0' && c <= '9');
}

int parseToInt(char c){
    return c - '0';
}

void assignValues(string& tokens, string& valuation){
    string result;
    int i = 0;
    while(tokens[i] != '\0'){
        if(isDigit(tokens[i])){
            int n = tokens[i] - '0';
            if(isDigit(tokens[i+1])){
                n *= 10;
                n += parseToInt(tokens[i+1]);
                i++;
            }
            result += valuation[n];
        } else {
            result += tokens[i];
        }
        i++;
    }
    tokens = result;
}

int evaluate(string tokens, string valuation){

    Stack values;
    Stack operators;

    for(char c: tokens){
        if(c == ' ') continue;
        else if (c == '~'){
            operators.StackUp(c);
        }
        else if(c == '('){
            operators.StackUp(c);
        }
        else if(isDigit(c)){
            values.StackUp(c);
        }
        else if(c == ')'){
            while (operators.GetIten() != '(')
            {
                if(operators.GetIten() == '~'){
                    values.StackUp(applyNeg(values.Unstack()));
                    operators.Unstack();
                    break;
                }
                int val2 = parseToInt(values.GetIten());
                values.Unstack();

                int val1 = parseToInt(values.GetIten());
                values.Unstack();

                char op = operators.GetIten();
                operators.Unstack();

                values.StackUp(applyOP(val1, val2, op) + '0');

            }
            if(!operators.Empty()) operators.Unstack();
        }
        else
        {
            while(!operators.Empty() && precedence(operators.GetIten()) >= precedence(c)){
                
                if(operators.GetIten() == '~') {
                    values.StackUp(applyNeg(values.Unstack()));
                    operators.Unstack();
                    break;
                }
                
                int val2 = parseToInt(values.GetIten());
                values.Unstack();

                int val1 = parseToInt(values.GetIten());
                values.Unstack();

                char op = operators.GetIten();
                operators.Unstack();

                values.StackUp(applyOP(val1, val2, op) + '0');
            }
            operators.StackUp(c);
        }
    }

    while(!operators.Empty()){

        if(operators.GetIten() == '~') {
            values.StackUp(applyNeg(values.Unstack()));
            operators.Unstack();
            break;
        }

        int val2 = parseToInt(values.GetIten());
        values.Unstack();

        int val1 = parseToInt(values.GetIten());
        values.Unstack();

        char op = operators.GetIten();
        operators.Unstack();
        
        values.StackUp(applyOP(val1, val2, op) + '0');
    }

    return parseToInt(values.GetIten());
}

/*void assignValuesSatisfaction(string& tokens, string valuation, BinaryTree& tree){
    string r = "", l = "";
    int i = 0; bool done = false;
    while(tokens[i] != '\0'){
        if(isDigit(tokens[i])){
            int n = tokens[i] - '0';
            if(isDigit(tokens[i+1])){
                n *= 10; n += (tokens[i+1] + '0');
                i++;
            }
            if (!isDigit(valuation[n]) && !done){
                done = true;
                l += '1';
                r += '0';
            } else if(isDigit(valuation[n])){
                r += valuation[n];
                l += valuation[n];
            } else {
                r += tokens[i];
                l += tokens[i];
            }
        } else {
            r += tokens[i];
            l += tokens[i];
        }
        i++;
    }
    tree.InsertRight(r);
    tree.InsertLeft(l);
    //tokens = result;
    if(!done){
        assignValuesSatisfaction(tokens, valuation, tree);
    }
}*/

/*int satisfaction(string tokens, string valuation){
    
    BinaryTree tree;
    tree.SetRoot(tokens);
    assignValuesSatisfaction(tokens, valuation, tree);
    
}*/

int main(int argc, char* argv[]){
    int opt;
    
    tokens = argv[2];
    valuation = argv[3];

    while ((opt = getopt(argc, argv, "ae")) != -1) {
        switch (opt) {
            case 'a':
                assignValues(tokens, valuation);
                cout << tokens << endl;
                cout << evaluate(tokens, valuation) << endl;
                cout << "FUNFA" << endl;
                break;
            case 'e':
                break;
            default:
                return 1;
        }
    }

    return 0;
}
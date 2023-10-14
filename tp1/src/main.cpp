#include <iostream>
#include <string.h>
#include <getopt.h>
#include "../include/Stack.h"
#include "../include/BinaryTree.h"

using namespace std;

#define EVALUATE 1
#define SATISFACTION 2

const int MAX = 1000000;

string tokens, valuation;
int possibility [MAX]; string expression [MAX];
int s = 0;

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

int evaluate(string tokens){

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

int assignValuesSatisfaction(string& tokens, string valuation, BinaryTree& tree, Node* p, int position){
    string r = "", l = "";
    int i = 0; bool done = false;
    while(i != position){
        r = tokens[i]; l = tokens[i];
        i++;
    }
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
                position = i;
            } else if(isDigit(valuation[n])){
                r += valuation[n];
                l += valuation[n];
            }
        } else {
            r += tokens[i];
            l += tokens[i];
        }
        i++;
    }
    if(done){
        tree.InsertRight(p, r);
        tree.InsertLeft(p, l);
    }
    return position;
}

void buildTree(string tokens, string valuation, BinaryTree& tree, Node* p){
    int position = 0;
    if(p!= nullptr){
        cout << p->GetExpression() << endl;
        buildTree(tokens, valuation, tree, p->GetLeft());
        buildTree(tokens, valuation, tree, p->GetRight());
        position = assignValuesSatisfaction(tokens, valuation, tree, p, position);
    }
}

void byLevel(string tokens, BinaryTree& tree, Node* p){
    if(p->GetRight() != nullptr){
        byLevel(tokens, tree, p->GetLeft());
        byLevel(tokens, tree, p->GetRight());
    } else{
        possibility[s] = evaluate(p->GetExpression());
        expression[s] = p->GetExpression();
        s++;
    }
}

void satisfaction(string tokens, string valuation){
    BinaryTree tree;
    tree.SetRoot(tokens);
    Node* p = tree.GetRoot();
    assignValuesSatisfaction(tokens, valuation, tree, p, 0);
    buildTree(tokens, valuation, tree, p);
    byLevel(tokens, tree, p);
}

void printPossibility(string tokens, string valuation) {
    int trueCount = 0;
    string alteredValuation = valuation;
    int index;
    for (int i = 0; i < s; i++) {
        if (possibility[i] == 1) {
            trueCount++;
            index = i;
            if (trueCount == s) {
                int j = 0;
                while (alteredValuation[j] != '\0') {
                    if (alteredValuation[j] == 'e') {
                        alteredValuation[j] = 'a';
                    }
                    j++;
                }
                cout << "1 " << alteredValuation << endl;
                return; 
            }
        }
    }

    if (trueCount == 0) {
        cout << "0" << endl;
        return;
    } else if(trueCount == 1){
        alteredValuation = expression[index];
        int i = 0; string result = "";
        while(alteredValuation[i] != '\0'){
            if(isDigit(alteredValuation[i])){
                result += alteredValuation[i];
            }
            i++;
        }
        cout << "1 " << result << endl;
    }
}

int main(int argc, char* argv[]){
    int opt;
    
    tokens = argv[2];
    valuation = argv[3];

    while ((opt = getopt(argc, argv, "as")) != -1) {
        switch (opt) {
            case 'a':
                assignValues(tokens, valuation);
                cout << tokens << endl;
                cout << evaluate(tokens) << endl;
                break;
            case 's':
                satisfaction(tokens, valuation);
                printPossibility(tokens, valuation);
                break;
            default:
                return 1;
        }
    }

    return 0;
}
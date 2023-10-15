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
int result [MAX]; string expression [MAX];
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

void assignValuesSatisfaction(string tokens, string valuation, BinaryTree& tree, Node* p){
    string r = tokens, l = tokens;
    int i = 0; bool done = false;
    while(r[i] != '\0'){
        if(r[i] == 'a' || r[i] == 'e'){
            r[i] = '1';
            l[i] = '0';
            done = true;
            break;
        }
        i++;
    }
    if(done){
        tree.InsertRight(p, r);
        tree.InsertLeft(p, l);
    }
}

void buildTree(string tokens, string valuation, BinaryTree& tree, Node* p){
    if(p != nullptr){
        assignValuesSatisfaction(p->GetExpression(), valuation, tree, p);
        buildTree(p->GetExpression(), valuation, tree, p->GetLeft());
        buildTree(p->GetExpression(), valuation, tree, p->GetRight());
    }
}

string removeNoDigits(string tokens){
    string result = "";
    for(char c : tokens){
        if(isDigit(c)) result += c;
    }
    return result;
}

void byLevel(Node* p){
    if(p->GetRight() != nullptr){
        byLevel(p->GetLeft());
        byLevel(p->GetRight());
    } else{
        result[s] = evaluate(p->GetExpression());
        expression[s] = removeNoDigits(p->GetExpression());
        s++;
    }
}

string changeTokens(string tokens, string valuation){
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
    return result;
}

void satisfaction(string tokens, string valuation){
    BinaryTree tree;
    tree.SetRoot(changeTokens(tokens, valuation));
    Node* p = tree.GetRoot();
    buildTree(tokens, valuation, tree, p);
    byLevel(p);
}

void printResult() {
    bool exists = false;
    bool all_true = true;
    bool any_true = false;

    for (int i = 0; i < tokens.size(); i++) {
        if (valuation[i] == 'e' && result[i] == 1) {
            exists = true;
            break;
        }
        if (valuation[i] == 'a' && result[i] == 0) {
            all_true = false;
        }
        if (valuation[i] == 'e' && result[i] == 1) {
            any_true = true;
        }
    }

    if (exists) {
        cout << "1 ";
        for (int i = 0; i < tokens.size(); i++) {
            if (valuation[i] == 'e' && result[i] == 1) {
                cout << expression[i];
            }
        }
        cout << endl;
    } else if (all_true) {
        cout << "1 ";
        for (int i = 0; i < tokens.size(); i++) {
            if (valuation[i] == 'a') {
                cout << expression[i];
            }
        }
        cout << endl;
    } else if (any_true) {
        cout << "1 ";
        for (int i = 0; i < tokens.size(); i++) {
            if (valuation[i] == 'e' && result[i] == 1) {
                cout << expression[i];
            }
        }
        cout << endl;
    } else {
        cout << "0" << endl;
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
                cout << evaluate(tokens) << endl;
                break;
            case 's':
                satisfaction(tokens, valuation);
                printResult();
                break;
            default:
                return 1;
        }
    }

    return 0;
}
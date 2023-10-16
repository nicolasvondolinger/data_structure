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

int evaluate(string tokens) {
    Stack values;
    Stack operators;

    for (char c : tokens) {
        if (c == ' ') continue;
        else if (c == '~') {
            operators.StackUp(c);
        } else if (c == '(') {
            operators.StackUp(c);
        } else if (isdigit(c)) {
            values.StackUp(c);
        } else if (c == ')') {
            while (operators.GetIten() != '(') {
                while (operators.GetIten() == '~') {
                    char v = values.Unstack();
                    values.StackUp(applyNeg(v));
                    operators.Unstack();
                }

                if (operators.GetIten() != '(') {
                    int val2 = parseToInt(values.GetIten());
                    values.Unstack();

                    int val1 = parseToInt(values.GetIten());
                    values.Unstack();

                    char op = operators.GetIten();
                    operators.Unstack();

                    values.StackUp(applyOP(val1, val2, op) + '0');
                }
            }
            if (!operators.Empty()) operators.Unstack();
        }
        else {
            while (!operators.Empty() && precedence(operators.GetIten()) >= precedence(c)) {
                if (operators.GetIten() == '~') {
                    char v = values.Unstack();
                    values.StackUp(applyNeg(v));
                    operators.Unstack();
                }else{
                    int val2 = parseToInt(values.GetIten());
                    values.Unstack();

                    int val1 = parseToInt(values.GetIten());
                    values.Unstack();

                    char op = operators.GetIten();
                    operators.Unstack();

                    values.StackUp(applyOP(val1, val2, op) + '0');
                }
            }
            operators.StackUp(c);
        }
    }

    while (!operators.Empty()) {
        if (operators.GetIten() == '~') {
            char v = values.Unstack();
            values.StackUp(applyNeg(v));
            operators.Unstack();
        } else{
            int val2 = parseToInt(values.GetIten());
            values.Unstack();

            int val1 = parseToInt(values.GetIten());
            values.Unstack();

            char op = operators.GetIten();
            operators.Unstack();

            values.StackUp(applyOP(val1, val2, op) + '0');
        }
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
        //cout << expression[s] << endl;
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

/*string tokens, valuation;
int result [MAX]; string expression [MAX];*/
void printResult() {
    int i = 0; string answer = "";
    while(valuation[i] != '\0'){
        char c = valuation[i];
        if(c == '1' || c == '0'){
            answer += c;
        } else if (c == 'e'){
            int j = 0; int d1 = 0, d0 = 0;
            while(j < s){
                string exp = expression[j];
                if(exp[i] == '1' && result[j] == 1) d1++;
                else if(exp[i] == '0' && result[j] == 1) d0++;
                j++;
            }
            if (d0 >= 1 && d1 >= 1) answer += 'a';
            else if (d0 >= 1) answer += '0';
            else if (d1 >= 1) answer += '1';
            else {
                cout << 0 << endl;
                return;
            }
        } else if (c == 'a'){
            int j = 0;
            while(j < s){
                if(result[j] != 1) {
                    cout << 0 << endl; return;
                }
                j++;
            }
        }
        i++;
    }
    cout << "1 "<< answer << endl;
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
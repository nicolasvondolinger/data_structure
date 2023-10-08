#include <iostream>
#include <string.h>
#include "../include/Stack.h"
//#include "../include/BinaryTree.h"

using namespace std;

#define EVALUATE 1
#define SATISFACTION 2

static int chosenop;
char outnome[100];
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
        case '|': return a + b;
        case '&': return a * b;
        default: return 1;
    }
}

char applyNeg(char a){
    switch(a){
        case '0': return '1';
        case '1': return '0';
        default: return ' ';
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
    for(char c : tokens){
        if(isDigit(c)){
            int n = c - '0';
            result += valuation[n];
        } else{
            result += c;
        }
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

void parse_args(int argc,char ** argv){

    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " -a|-s \"tokens\" valuation\n";
        exit(1); // Saia com código de erro
    }

    // Processar argumentos manualmente
    if (strcmp(argv[1], "-a") == 0) {
        chosenop = EVALUATE;
    } else if (strcmp(argv[1], "-s") == 0) {
        chosenop = SATISFACTION;
    }

    tokens = argv[2];
    valuation = argv[3];

    // Verifique se uma operação válida foi escolhida
    /*if (chosenop == NONE || tokens == nullptr || valuation == 0) {
        std::cerr << "Argumentos inválidos.\n";
        exit(1); // Saia com código de erro
    }*/
}

int main(int argc, char ** argv){

    parse_args(argc, argv);
    switch(chosenop){
        case EVALUATE:
            assignValues(tokens, valuation);
            cout << tokens << endl;
            cout << evaluate(tokens, valuation) << endl;
            break;
        default:
            break;
    }
    cout << "FUNFA" << endl;

    return 0;
}
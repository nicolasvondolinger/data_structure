#include <iostream>
#include <string.h>
#include <getopt.h>
#include "../include/Stack.h"
#include "../include/BinaryTree.h"

using namespace std;

const int MAX = 1000000;

string tokens, valuation; //Variáveis globais para facilitar o acesso
int result [MAX]; string expression [MAX]; //Arrays globais que armazenam os resultados das folhas e a espressão que gerou tal resultado, respectivamente, no mesmo index
int s = 0;

//Retorna a precedencia de cada operador, de acordo com o seu peso em expressões lógicas
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

//Retorna o valor resultante da operação passada como parametro das duas variaveis
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

//Retorna o valor oposto ao respectivo char('1' se recebe '0' e vice-versa)
char applyNeg(char a){
    switch(a){
        case '0': return '1';
        case '1': return '0';
        default: throw std::runtime_error("Invalid Value");
    }
}

//Verifica se o char passado como parametro seria considerado digito caso fosse do tipo int
bool isDigit(char c){
    return (c >= '0' && c <= '9');
}

//Passa o char recebido como parametro para o tipo int
int parseToInt(char c) {
    if (isDigit(c)) {
        return c - '0';
    }
    throw std::invalid_argument("Caractere não é um dígito");
}

//Atribui o valor de cada posição de valuation a sua respectiva variável em tokens
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

//Retorna o valor final resultante da expressao logica tokens
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

//Cria as strings dos nós filhos da direita e da esquerda, se for necessário, e caso seja, insere o resultado em cada um
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

//Constroi a arvore recursivamente até que não seja necessário criar novos filhos
void buildTree(string tokens, string valuation, BinaryTree& tree, Node* p){
    if(p != nullptr){
        assignValuesSatisfaction(p->GetExpression(), valuation, tree, p);
        buildTree(p->GetExpression(), valuation, tree, p->GetLeft());
        buildTree(p->GetExpression(), valuation, tree, p->GetRight());
    }
}

//Retorna uma nova string basesada em tokens, mas sem caracteres que não sejam digitos
string removeNoDigits(string tokens){
    string result = "";
    for(char c : tokens){
        if(isDigit(c)) result += c;
    }
    return result;
}

//Calcula o resultado de cada uma das folhas das arvores, armazena o resultado em result e a expressao sem os caracteres que não são digitos em expression 
void byLevel(Node* p){
    if(p->GetRight() != nullptr){
        byLevel(p->GetLeft());
        byLevel(p->GetRight());
    } else{
        result[s] = evaluate(p->GetExpression());
        expression[s] = removeNoDigits(p->GetExpression());
        //cout << expression[s] << " : " << result[s] << endl;
        s++;
    }
}

//Retorna a expressão tokens valorada com os valores de valuation 
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

//Função chamada para executar a satisfabilidade
void satisfaction(string tokens, string valuation){
    BinaryTree tree;
    tree.SetRoot(changeTokens(tokens, valuation));
    Node* p = tree.GetRoot();
    buildTree(tokens, valuation, tree, p);
    byLevel(p);
}

//Função chamada para printar o resultado da satisfabilidade
void printResult() {
    int i = 0; string answer = "";
    while(valuation[i] != '\0'){
        char c = valuation[i];
        if(c == '1' || c == '0'){
            answer += c;
        } else if (c == 'e' || c == 'a'){
            int j = 0; int d1 = 0, d0 = 0;
            while(j < s){
                string exp = expression[j];
                if(exp[i] == '1' && result[j] == 1) d1++;
                else if(exp[i] == '0' && result[j] == 1) d0++;
                j++;
            }
            if (d0 >= 1 && d1 >= 1 && c == 'e') answer += 'a';
            else if (d0 >= 1 && d1 >= 1 && c == 'a') {
                string resp = "";
                for(char q : valuation){
                    if(q == 'e') resp += '1';
                    else resp += q;
                }
                cout << "1 "<< resp << endl; return;
            } else if (d0 >= 1) answer += '0';
            else if (d1 >= 1) answer += '1';
            else {
                cout << 0 << endl;
                return;
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
                try {
                    assignValues(tokens, valuation);
                    cout << evaluate(tokens) << endl;
                } catch (const std::exception &e) {
                    cerr << "Erro ao calcular: " << e.what() << endl;
                    return 1;
                }
                break;
            case 's':
                try {
                    satisfaction(tokens, valuation);
                    printResult();
                } catch (const std::exception &e) {
                    cerr << "Erro ao calcular a satisfabilidade: " << e.what() << endl;
                    return 1;
                }
                break;
            default:
                return 1;
        }
    }

    return 0;
}
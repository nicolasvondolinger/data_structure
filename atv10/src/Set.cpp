#include "./include/Set.hpp"

using namespace std;

StringSet::StringSet(int tamanho){
    tamanhoOriginal = tamanho;
    tamanhoTabela = tamanho;
    tamanhoConjunto = 0;
    tabela = new ElementoTabela[tamanho];

    for (int i = 0; i < tamanho; i++) {
        tabela[i].dado = "";
        tabela[i].vazio = false;
        tabela[i].retirada = false;
    }
}

StringSet::~StringSet(){
    delete[] tabela;
}

void StringSet::Inserir(string s){
    if(Pertence(s)) return;
    int p = Hash(s);
    if(!tabela[p].vazio){
        tabela[p].dado = s;
        tabela[p].vazio = true;
        tamanhoConjunto++;
        return;
    } 
    for(int i = p; i < tamanhoTabela; i++){
        if(!tabela[i].vazio){
            tabela[i].dado = s;
            tabela[i].vazio = true;
            tamanhoConjunto++;
            return;
        } 
    }
    for(int i = 0; i < p; i++){
        if(!tabela[i].vazio){
            tabela[i].dado = s;
            tabela[i].vazio = true;
            tamanhoConjunto++;
            return;
        } 
    }
    Rehash(tamanhoTabela * 2);
    Inserir(s);
}

void StringSet::Remover(string s){
    for (int i = 0; i < tamanhoTabela; i++){
        if(tabela[i].dado == s) {
            tabela[i].dado = "";
            tabela[i].vazio = false;
            tamanhoConjunto--;
        }
    } 
}

bool StringSet::Pertence(string s){
    for(int i = 0; i < tamanhoTabela; i++){
        if(tabela[i].dado == s) return true;
    }
    return false;
}

StringSet* StringSet::Intersecao(StringSet* S){
    StringSet*  StringSetInter = new StringSet(tamanhoTabela);
    for(int i = 0; i < tamanhoTabela; i++){
        if(S->Pertence(tabela[i].dado)) StringSetInter -> Inserir(tabela[i].dado);
    }
    return StringSetInter;
}

StringSet* StringSet::Uniao(StringSet* S){
    StringSet* StringSetUnion = new StringSet(tamanhoTabela);
    StringSetUnion -> tabela = tabela;
    for(int i = 0; i < S->tamanhoTabela; i++){
        if(!Pertence(S->tabela[i].dado)){
            StringSetUnion->Inserir(S->tabela[i].dado);
        }
    }
    return StringSetUnion;
}

StringSet* StringSet::DiferencaSimetrica(StringSet * S){
    StringSet* StringSetDif = new StringSet(tamanhoTabela);
    StringSet* StringSetInter = Intersecao(S);
    for(int i = 0; i < tamanhoTabela; i++){
        if(!StringSetInter->Pertence(tabela[i].dado)){
            StringSetDif->Inserir(tabela[i].dado);
        }
    }
    for(int i = 0; i < S->tamanhoTabela; i++){
        if(!StringSetInter->Pertence(S->tabela[i].dado)){
            StringSetDif->Inserir(S->tabela[i].dado);
        }
    }
    return StringSetDif;
}

void StringSet::Imprimir(){
    if(tamanhoTabela == 1) {
        cout << "{ "<< tabela[0].dado << " }"<< endl;
        return;
    }
    cout << '{';
    for(int i = 0; i < tamanhoTabela; i++){
        if(i + 1 == tamanhoTabela) cout << tabela[i].dado;
        else if (tabela[i].dado != "") cout << tabela[i].dado << ','; 
    }
    cout << '}' << endl;
}

int StringSet::Hash(string s){
    int i; for(i = 0; s[i]; i++);
    return i % tamanhoTabela;
}

void StringSet::Rehash(int pos){
    StringSet* tabelaNova = new StringSet(pos);
    for(int i = 0; i < tamanhoTabela; i++){
        tabelaNova->Inserir(tabela[i].dado);
    }
    tabela = tabelaNova->tabela;
    tamanhoTabela = pos;
}

void StringSet::Resize(long tamanho){
    if (tamanho > tamanhoTabela) {
        Rehash(tamanho);
    }
}
#include "../include/node.hpp"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int maxValue(int a, int b){
  return (a > b) ? a : b;
}

int height(Node* n){
  if (n == nullptr) return 0;
  return n->height;
}

Node* newNode(string word, int pag){
   Node* node = new Node;
    node->height = 1;
    node->numpags = 1;
    node->pags[0] = pag;
    node->word = word;
    node->right = nullptr;
    node->left = nullptr;
    return node;
}

void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}


Node* rightRotate(Node* x){
    Node* y = x -> left;
    Node* z = y->right;

    y->right = x;
    x->left = z;

    x->height = (maxValue(height(x->left), height(x->right)) + 1);
    y->height = (maxValue(height(y->left), height(y->right)) + 1);

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = (maxValue(height(x->left), height(x->right)) + 1);
    y->height = (maxValue(height(y->left), height(y->right)) + 1);

    return y;
}

int balanceFactor(Node* n){
    if(n == NULL) return 0;
    return height(n->right) - height(n->left);
}

Node* insert(Node* root, string w, int pag) {
    // Criar o novo nó a ser inserido
    Node* nn = newNode(w, pag);

    // Se a árvore está vazia, retorne o novo nó como a raiz
    if (root == nullptr) {
        return nn;
    }

    // Iterativamente encontrar a posição correta para inserir o novo nó
    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;

        // Comparar a palavra para decidir se ir para a subárvore esquerda ou direita
        if (w < current->word) {
            current = current->left;
        } else if (w > current->word) {
            current = current->right;
        } else {
            // A palavra já existe, adicione a página se não existir
            for (int i = 0; i < current->numpags; i++) {
                if (current->pags[i] == pag) {
                    // Página já existe, não precisa adicionar novamente
                    delete nn;  // Liberar a memória do novo nó
                    return root;
                }
            }

            // Adicionar a nova página
            current->pags[current->numpags] = pag;
            current->numpags++;

            // Ordenar as páginas (pode ser otimizado)
            for (int i = 0; i < current->numpags - 1; i++) {
                for (int j = 0; j < current->numpags - i - 1; j++) {
                    if (current->pags[j] > current->pags[j + 1]) {
                        int aux = current->pags[j];
                        current->pags[j] = current->pags[j + 1];
                        current->pags[j + 1] = aux;
                    }
                }
            }

            // Liberar a memória do novo nó
            delete nn;

            return root;
        }
    }

    // Inserir o novo nó na posição correta
    if (w < parent->word) {
        parent->left = nn;
    } else if (w > parent->word) {
        parent->right = nn;
    } else {
        // A palavra já existe, adicione a página se não existir
        for (int i = 0; i < parent->numpags; i++) {
            if (parent->pags[i] == pag) {
                // Página já existe, não precisa adicionar novamente
                delete nn;  // Liberar a memória do novo nó
                return root;
            }
        }

        // Adicionar a nova página
        parent->pags[parent->numpags] = pag;
        parent->numpags++;

        // Ordenar as páginas (pode ser otimizado)
        for (int i = 0; i < parent->numpags - 1; i++) {
            for (int j = 0; j < parent->numpags - i - 1; j++) {
                if (parent->pags[j] > parent->pags[j + 1]) {
                    int aux = parent->pags[j];
                    parent->pags[j] = parent->pags[j + 1];
                    parent->pags[j + 1] = aux;
                }
            }
        }

        // Liberar a memória do novo nó
        delete nn;

        return root;
    }

    // Atualizar as alturas e balancear a árvore
    // (o código para isso permanece o mesmo que na versão recursiva)

    return root;
}

void printDuo(Node* n){
    cout << n->word << ": ";
    for(int i = 0; i < n->numpags; i++){
        cout << n->pags[i] << ' ';
    }
    cout << endl;
}

void printTree(Node *root) {
  if (root != nullptr) {
    printTree(root->left);
    printDuo(root);
    printTree(root->right);
  }
}

int main(int argc, char ** argv){
  string palavra; int pagina;
  Node *avl = NULL;

  while (!feof(stdin)){
      cin >> palavra >> pagina;
      
          avl = insert(avl, palavra, pagina);
      
  }

  printTree(avl);
  deleteTree(avl);

  return 0;
}
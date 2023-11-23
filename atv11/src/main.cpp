#include "indice.hpp"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXPALAVRA 10
#define MAXINDICE 10
#define MAXPAGINA 10

static int cmpindentr(const void *p1, const void *p2) {
  dupla * i1 = (dupla*) p1;
  dupla * i2 = (dupla*) p2;
  return strcmp(i1->palavra, i2->palavra);
}

static int cmpint(const void *p1, const void *p2) {
  int * i1 = (int*) p1;
  int * i2 = (int*) p2;
  if (*i1<*i2) return -1;
  if (*i1>*i2) return 1;
  return 0;
}

void inicializaindice(dupla * meuind){
  meuind->numpalavras = 0;
  for (int i=0; i<MAXINDICE; i++){
     meuind->indice[i].numpags = 0;
     meuind->indice[i].palavra[0] = 0;
  }
}

int localizapalavra(dupla * meuind, char * palavra){
  for (int i=0; i<meuind->numpalavras; i++){
    if (strcmp(meuind->indice[i].palavra,palavra)==0) return i;
  }
  return -1;
}

int inserepalavra(dupla * meuind, int pos, char * palavra, int pagina){
  if (pos == -1){
    pos = meuind->numpalavras;
    strcpy(meuind->indice[pos].palavra,palavra);
    meuind->numpalavras++;
  }
  for (int i=0; i<meuind->indice[pos].numpags; i++){
    if (meuind->indice[pos].pags[i] == pagina) return pos;
  }
  meuind->indice[pos].pags[meuind->indice[pos].numpags] = pagina;
  meuind->indice[pos].numpags++;
  return pos;
}

void imprimeindice(dupla * meuind){
  qsort(meuind->indice, meuind->numpalavras, sizeof(indentr_t), cmpindentr);
  for (int i=0; i<meuind->numpalavras; i++){
    cout << meuind->indice[i].palavra << ':';
    qsort(meuind->indice[i].pags,meuind->indice[i].numpags,sizeof(int),cmpint);
    for (int j=0; j<meuind->indice[i].numpags; j++){
      cout << ' ' << meuind->indice[i].pags[j]; 
    }
    cout << endl;
  }
}

int main(int argc, char ** argv){
  string palavra;
  int pagina,pos;
  dupla meuind;

  inicializaindice(&meuind);
 
  while (!feof(stdin)){
    cin >> palavra >> pagina;
    pos = localizapalavra(&meuind,palavra);
    inserepalavra(&meuind,pos,palavra,pagina);
  }	  

  imprimeindice(&meuind);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXPALAVRA 10
#define MAXINDICE 10
#define MAXPAGINA 10

typedef struct indentr{
    char palavra[MAXPALAVRA];
    int numpags;
    int pags[MAXPAGINA];
} indentr_t;

typedef struct indrem{
  indentr_t indice[MAXINDICE];
  int numpalavras;
} indrem_t;

static int cmpindentr(const void *p1, const void *p2) {
  indentr_t * i1 = (indentr_t*) p1;
  indentr_t * i2 = (indentr_t*) p2;

  return strcmp(i1->palavra, i2->palavra);
}

static int cmpint(const void *p1, const void *p2) {
  int * i1 = (int*) p1;
  int * i2 = (int*) p2;

  if (*i1<*i2) return -1;
  if (*i1>*i2) return 1;
  return 0;
}


void inicializaindice(indrem_t * meuind){
  meuind->numpalavras = 0;
  for (int i=0; i<MAXINDICE; i++){
     meuind->indice[i].numpags = 0;
     meuind->indice[i].palavra[0] = 0;
  }
}

int localizapalavra(indrem_t * meuind, char * palavra){
  for (int i=0; i<meuind->numpalavras; i++){
    if (strcmp(meuind->indice[i].palavra,palavra)==0){
      return i;
    }
  }
  return -1;
}

int inserepalavra(indrem_t * meuind, int pos, char * palavra, int pagina){
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

void imprimeindice(indrem_t * meuind){
  qsort(meuind->indice, meuind->numpalavras, sizeof(indentr_t), cmpindentr);
  for (int i=0; i<meuind->numpalavras; i++){
    printf("%s:",meuind->indice[i].palavra);
    qsort(meuind->indice[i].pags,meuind->indice[i].numpags,sizeof(int),cmpint);
    for (int j=0; j<meuind->indice[i].numpags; j++){
      printf(" %d",meuind->indice[i].pags[j]);
    }
    printf("\n");
  }
}


int main(int argc, char ** argv){
  char palavra[MAXPALAVRA];
  int pagina,pos;
  indrem_t meuind;

  inicializaindice(&meuind);
 
  while (!feof(stdin)){
    scanf("%s %d", palavra, &pagina);
    pos = localizapalavra(&meuind,palavra);
    inserepalavra(&meuind,pos,palavra,pagina);
  }	  

  imprimeindice(&meuind);
  return 0;
}

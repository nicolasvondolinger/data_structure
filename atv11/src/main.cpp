#include "avlTree.hpp"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char ** argv){
  string palavra;
  int pagina,pos;
  avlTree avl;

  inicializaindice();
 
  while (!feof(stdin)){
    cin >> palavra >> pagina;
    pos = localizapalavra(&meuind,palavra);
    inserepalavra(&meuind,pos,palavra,pagina);
  }	  

  imprimeindice();

  return 0;
}
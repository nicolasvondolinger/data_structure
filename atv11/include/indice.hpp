#ifndef INDREMHPP_H
#define INDREMHPP_H

#define MAXPALAVRA 10
#define MAXINDICE 10
#define MAXPAGINA 10

#include <iostream>

using namespace std;

class Dupla {
  public:
      string palavra;
      int numpags;
      int pags[MAXPAGINA];
};

class IndRem {
  public:
      Dupla indice[MAXINDICE];
      int numpalavras;
};

#endif
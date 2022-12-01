#include <stdio.h>
#include <iostream>
using namespace std;

//bf é fator de balanço
struct noAVL{
    int val, altura, bf; //hdir - hesq
    struct noAVL *esq,dir;
};

struct noAVL * rotDir(struct noAVL *raiz){
    struct noAVL * novaRaiz = raiz->esq;
    raiz->esq = raiz->dir;
    novaRiaz->dir = raiz;
    
    atualizar(raiz);
    atuaslizar(novaRaiz);
    
    return novaRaiz;
};

struct noAVL* rotEsq(struct  noAVL *raiz){
    
};

void atualuzar(struct noAVL *raiz){
  if(raiz != NULL){
      
      int hesq = 0, hdir = 0;
      if(raiz->esq != NULL){
          hesq = raiz->esq->altura;
      }
      if(raiz->dir != NULL){
          hdir = raiz->dir->altura;
      }
      //raiz->altura
  }  
};

int main() {
    // Write C++ code here
    std::cout << "Hello world!";

    return 0;
}

// Online C compiler to run C program online
#include <stdio.h>
#include <iostream>
using namespace std;

struct noBst{
    int val;
    struct noBst* esq;
    struct noBst* dir;
};

struct bst{
  
  struct noBst* raiz;
  int tamanho;
    
};

struct bst* alocarBst(){
    struct bst* arv = (struct bst*)malloc(sizeof(struct bst));
    arv->raiz = NULL;
    arv->tamanho = 0;
    
    return arv;
};

struct noBst* alocarNovoNo(int val){
    
    struct noBst *raiz = (struct noBst*)malloc(sizeof(struct noBst));
    
    raiz->val = val;
    raiz->esq = NULL;
    raiz->dir = NULL;
    
    return raiz;
    
};

void inserirNoRec(struct noBst** raiz, struct noBst *novoNo){
    
    if((*raiz) == NULL)
        (*raiz) = novoNo;
    else{
        if(novoNo->val > (*raiz)->val)
            inserirNoRec(&(*raiz)->dir, novoNo);
        else
            inserirNoRec(&(*raiz)->esq, novoNo);
    }
    
}

void inserirNoIte(){
    
}

//precisa ajustar
void buscaRec(struct noBst *raiz, int val){
    
    if((*raiz) == NULL)
        return false;
    else{
        
    }
    
}



int main() {
    
    //struct noBst *raiz = NULL;
    
    

    return 0;
}

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
    
    //se for nulo, vai apenas inserir o novoNo
    if((*raiz) == NULL)
        (*raiz) = novoNo;
    else{
        
        //se o valor for maior que verificado, vai passar a direita como paramêtro até que raiz seja == null, se não, passa a esquerda
        if(novoNo->val > (*raiz)->val)
            inserirNoRec(&(*raiz)->dir, novoNo);
        else
            inserirNoRec(&(*raiz)->esq, novoNo);
    }
    
}

void inserirNoIte(struct bst *arv, struct noBst *novoNo){
    
    if (arv->raiz == NULL) {
        arv->raiz = novoNo;
    } else {
        struct noBst *aux = arv->raiz;
        while (aux != NULL) {
            if (novoNo->val > aux->val)
                aux = aux->dir;
            else
                aux = aux->esq;
            }
            aux = novoNo;
    }
    
}

//precisa ajustar
bool buscaRec(struct noBst *raiz, int val){
    
    if( raiz == NULL)
        return false;
    else{
        
        //se for igual, retorna true, se não for, vai buscar na direita ou esquerda
        if(val == raiz->val){
            return true;
        }else if(val > raiz->val){
            buscaRec(raiz->dir, val);
        }else{
             buscaRec(raiz->esq, val);
        }
        
    }
    
}

bool buscaIt(struct bst *arv, int val) {
    
    if(arv->raiz == NULL){
        return false;
    }else{
        
        struct noBst *aux = arv->raiz;
        
        while(aux != NULL){
            
            if(val == aux->val){
                return true;
            }else if(val > aux->val){
                aux = aux->dir;
            }else{
                aux = aux->esq;
            }
            
        }
        return false;
    }
    
}

int main() {
    
    //struct noBst *raiz = NULL;
    
    

    return 0;
}

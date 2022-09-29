#include <iostream>

using namespace std;

struct arraylist{
  
  int* vetor;
  int qtdade;
  int tamanho;
    
};

struct arraylist* inicializar(int tamanho){
    
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    
    lista->vetor = (int*)calloc(tamanho, sizeof(int));
    lista->qtdade = 0;
    lista->tamanho = tamanho;
    
};

void duplicarLista(struct arraylist* lista){
    
    lista->vetor = (int*)realloc(lista->vetor, 2*lista->tamanho*sizeof(int));
    lista->tamanho = 2*lista->tamanho;
}

void inserirNoFim(struct arraylist* lista, int valor){
    
    if(lista->tamanho == lista->qtdade){
        duplicarLista(lista);
    }
    
    lista->vetor[lista->qtdade] = valor;
    lista->qtdade++;
    
}

void imprimirLista(struct arraylist* lista){
    
    printf("[");
    
    for(int i = 0; i < lista->qtdade; i++){
        
        printf(" %d ",lista->vetor[i]);
        
        if(i != (lista->qtdade-1)){
            printf(",");
        }
        
    }
    
    printf("] \n");
    
}

void inserirEmPosicao(struct arraylist* lista, int posicao, int valor){
    
    if(posicao >= 0 && posicao <= lista->tamanho){
        
        if(lista->qtdade == lista->tamanho){
            duplicarLista(lista);
        }
        
        for(int i = lista->qtdade; i >= posicao; i--){
            
            lista->vetor[i] = lista->vetor[i-1];
            
        }
        
        lista->vetor[posicao] = valor;
        lista->qtdade++;
        
    }else{
        printf("Posição inválida");
    }
    
}

void removerEmPosicao(struct arraylist* lista, int posicao){
    
    if(posicao >= 0 && posicao <= lista->tamanho){
        
        for(int i = posicao; i < lista->qtdade; i++){
            
            lista->vetor[i] = lista->vetor[i+1];
            
        }
        
        lista->qtdade--;
        
    }else{
        printf("Posição inválida");
    }
    
}

int obterElemento(struct arraylist* lista, int posicao){
    
    if(posicao >= 0 && posicao <= lista->tamanho){
        return lista->vetor[posicao];   
    }else{
        return 0;
    }
    
}

void atualizarElemento(struct arraylist* lista, int posicao, int valor){
    
    lista->vetor[posicao] = valor;
    
}

void removerNoFim(struct arraylist* lista){
    
    lista->qtdade--;
    
}

void inverterLista(struct arraylist* lista){
    
    int aux;
    
    for(int i = 0; i < (lista->qtdade)/2; i++){
        
        aux = lista->vetor[i];
        lista->vetor[i] = lista->vetor[lista->qtdade-1-i];
        lista->vetor[lista->qtdade-1-i] = aux;
    }
    
}


//ordem crescente
void buscaBinariaCres(struct arraylist* lista, int valor){
    
    int inicio = 0;
    int fim = lista->qtdade-1;
    int meio = (inicio+fim)/2;
    
    int teste = 0;
    
    //printf("inicio: %d, meio: %d, fim: %d \n", inicio, meio, fim);
    
    while(teste == 0){
        
        if(lista->vetor[meio] == valor){
            teste = 1;
            printf("Encontrado \n");
            //printf("indice: %d", meio+1);
        }
        
        if(lista->vetor[meio] < valor){
            
            inicio = meio+1;
            meio = (inicio+fim)/2;
            
        }
        
        if(lista->vetor[meio] > valor){
            
            fim = meio-1;
            meio = (inicio+fim)/2;
            
        }
        
        
        if(inicio > fim){
            printf("Não encontrado \n");
            //printf("indice: %d", meio+1);
            teste = 1;
        }
        
        //printf("inicio: %d, meio: %d, fim: %d \n", inicio, meio, fim);
        
    }
}

//ordem decrescente
void buscaBinariaDec(struct arraylist* lista, int valor){
    
    int inicio = 0;
    int fim = lista->qtdade-1;
    int meio = (inicio+fim)/2;
    
    int teste = 0;
    
    //printf("inicio: %d, meio: %d, fim: %d \n", inicio, meio, fim);
    
    while(teste == 0){
        
        if(lista->vetor[meio] == valor){
            teste = 1;
            printf("Encontrado \n");
        }
        
        if(lista->vetor[meio] < valor){
            
            fim = meio-1;
            meio = (inicio+fim)/2;
            
        }
        
        if(lista->vetor[meio] > valor){
            
            inicio = meio+1;
            meio = (inicio+fim)/2;
            
        }
        
        
        if(inicio > fim){
            printf("Não encontrado \n");
            teste = 1;
        }
        
        //printf("inicio: %d, meio: %d, fim: %d \n", inicio, meio, fim);
        
    }
}

int main()
{
    int tamanho = 10;
    struct arraylist* lista = inicializar(tamanho);
    
    for(int i = 0; i < 20; i+=2){
        inserirNoFim(lista, i);
    }
    
    imprimirLista(lista);
    
    //inserirEmPosicao(lista, 2, 70);
    
    //imprimirLista(lista);
    
    //removerEmPosicao(lista, 8);
    
    //imprimirLista(lista);

    //printf("%d \n", obterElemento(lista, 2));
    
    //atualizarElemento(lista, 3, 54);
    
    //removerNoFim(lista);
    
    //imprimirLista(lista);
    
    //inverterLista(lista);
    
    imprimirLista(lista);
    
    //buscaBinariaCres(lista, 6);
    
    return 0;
}

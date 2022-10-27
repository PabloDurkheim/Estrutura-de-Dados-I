// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void countSort(int *v, int tamanho){

    int maior = v[0], menor = v[0];
    
    for(int i = 1; i < tamanho; i++){
        
        if(v[i] > maior){
            maior = v[i];
        }
         if(v[i] < menor){
            menor = v[i];
        }
        
    }
    
    cout << "Maior: " << maior << " | Menor: " << menor << endl;
    
    int novoTamanho = (maior-menor+1);
    int *contagem = (int*)calloc(novoTamanho, sizeof(int));
    
    
    for(int indice = menor, i = 0, w = 0; indice <= maior; indice++){
        
        bool mudou = false;
        for(int j = 0; j < tamanho; j++){
            
            if(v[j] == indice){
                contagem[i] = 1;
                i++;
                mudou = true;
                break;
            }
            
        }
        
        if(mudou == false){
            contagem[i] = 0;
            i++;
        }
        //cout << contagem[i-1] << " ";
    }
    
    for(int i = menor, w = 0; i <= maior; i++){
        
        if(contagem[i-menor] == 1){
            v[w] = i;
            w++;
       }
        
    }
     cout << endl;
    //exibirVetor(contagem, novoTamanho);
    
}

void exibirVetor(int *v, int tamanho){
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
     cout << endl;
}

int main() {
    
    int tamanho = 5;
    int *v = (int*)calloc(tamanho, sizeof(int));
    
    for(int i = 0; i < tamanho; i++){
        v[i] = rand() % 100;
    }
    
    exibirVetor(v, tamanho);
    
    countSort(v, tamanho);
    
    exibirVetor(v, tamanho);
    
    return 0;
}

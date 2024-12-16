// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void imprimir(int *v, int tam){
    
    for(int i = 0; i < tam; i++){
        cout << v[i] << " ";
    }
    
    cout<<endl<<endl;
    
}

//versão melhorada
void bubbleSort(int *v, int tam){
    
    for(int i = 0; i < (tam-1); i++){
        bool troca = false;
        
        cout << "--- Iteração: " << i << " ---" <<endl<<endl;
        
        for(int j = 0; j < (tam-i-1); j++){
            
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                troca = true;
            }
            imprimir(v, tam);
        }
        
        if(troca == false){
            return;
        }
        
    }
    
}

int main() {
    
    int tamanho = 5;
    int *v = (int*)calloc(tamanho, sizeof(int));
    
    for(int i = 0; i < tamanho; i++){
        v[i] = rand() % 100;
    }
    
    cout << "Vetor original: ";
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    cout << endl << endl;
    
    bubbleSort(v, tamanho);
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    return 0;
}

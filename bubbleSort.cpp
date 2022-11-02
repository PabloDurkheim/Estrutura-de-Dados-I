// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

//versão melhorada
void bubbleSort(int *v, int tam){
    
    for(int i = 0; i < (tam-1); i++){
        bool troca = false;
        
        for(int j = 0; j < (tam-i-1); j++){
            
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                troca = true;
            }
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
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    bubbleSort(v, tamanho);
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    return 0;
}

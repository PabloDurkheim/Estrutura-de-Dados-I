// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void imprimir(int *v, int tam){
    
    for(int i = 0; i < tam; i++){
        cout << v[i] << " ";
    }
    
    cout<<endl<<endl;
    
}

//é como se fosse o bubble sort, só que para a esquerda
void insertionSortIP(int *v, int tamanho){
   
    for (int i = 1; i < tamanho; i++) {   //i = indice da carta a ser inserida ordenada
        
        cout << "--- Iteração: " << i << " ---" <<endl<<endl;
        
        for (int j = i; j > 0; j--) {

            cout << "v["<<j-1<<"] > v["<<j<<"] ???"<<endl;
            cout << v[j-1] << " > " << v[j] << "?"<<endl;
            cout << "i: " << i << "     j: " << j << endl;
            
            if (v[j - 1] > v[j]) {
                int temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
            }
            else {
                break;
            }
            
            imprimir(v, tamanho);
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
    
    cout << endl<<endl;
    
    insertionSortIP(v, tamanho);
    
    return 0;
}

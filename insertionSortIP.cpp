// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

//é como se fosse o bubble sort, só que para a esquerda
void insertionSortIP(int *v, int tamanho){
   
    for (int i = 1; i < tamanho; i++) {   //i = indice da carta a ser inserida ordenada
        for (int j = i; j > 0; j--) {
            if (v[j - 1] > v[j]) {
                int temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
            }
            else {
                break;
            }
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
    
    insertionSortIP(v, tamanho);
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    return 0;
}

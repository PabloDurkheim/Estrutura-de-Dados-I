// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void swap(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int particiona(int* v, int ini, int fim){
    int pIndex = ini;
    int pivo = v[fim];
    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swap(v,i,pIndex);
            pIndex++;
        }
    }
    swap(v,pIndex,fim);
    return pIndex;
}

void quickSort(int* v, int ini, int fim){
    if(fim>ini){                        
        int indexPivo = particiona(v,ini,fim);
        cout << indexPivo << endl;
        quickSort(v,ini,indexPivo-1);
        quickSort(v,indexPivo+1,fim);   //indexPivo já está no seu local
    }
}

int main() {
    
    int tamanho = 4;
    int *v = (int*)calloc(tamanho, sizeof(int));
    
    v[0] = 5;
    v[1] = 2;
    v[2] = 7;
    v[3] = 1;
    
   // for(int i = 0; i < tamanho; i++){
     //   v[i] = rand() % 100;
    //}
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    quickSort(v, 0, tamanho-1);
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    return 0;
}

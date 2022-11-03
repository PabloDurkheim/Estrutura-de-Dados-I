// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void merge(int* v, int tamV, int* e, int tamE, int* d, int tamD){
   
   int indexV = 0;
   int indexE = 0;
   int indexD = 0;
   
   while(indexE < tamE && indexD < tamD){
       
       if(e[indexE] <= d[indexD]){
           v[indexV] = e[indexE];
           indexE++;
       }else{
           v[indexV] = d[indexD];
           indexD++;
       }
       
       indexV++;
       
   }
   
   while(indexE < tamE){
       v[indexV] = e[indexE];
       indexE++;
       indexV++;
   }
   
   while(indexD < tamD){
       v[indexV] = d[indexD];
       indexD++;
       indexV++;
   }
   
}

void mergeSort(int* v, int tamV){
    
    if(tamV > 1){
        
    int meio = tamV/2;
    int tamE = meio;
    int tamD = tamV - meio;
    
    int *Ve = (int*)calloc(meio, sizeof(int));
    
    for(int i = 0; i < tamE; i++){
        Ve[i] = v[i];
    }
    
    int *Vd = (int*)calloc(tamD, sizeof(int));
    
    for(int i = meio; i < tamV; i++){
        Vd[i-meio] = v[i];
    }
    
    mergeSort(Ve, tamE);
    mergeSort(Vd, tamD);
    merge(v, tamV, Ve, tamE, Vd, tamD);
    
    free(Ve);
    free(Vd);
            
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
    
    mergeSort(v, tamanho);
    
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    
    return 0;
}

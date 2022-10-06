#include <iostream>

using namespace std;

int INT_MAX = 1000000000;

//selectionSort Out-of-Place
void selectionSortOP(int* v, int tamanho){
    
    for(int i = 0; i < tamanho; i++){
        
        int iMenor = i;
        
        for(int j = i+1; j < tamanho; j++){
            
            if( v[j] < v[iMenor]){
                iMenor = j;
            }
            
        }
        
        int aux = v[i];
        
        v[i] = v[iMenor];
        v[iMenor] = aux;
    }
    
}

int main() {
    // Write C++ code here
    int *vDesord = (int *)malloc(6*sizeof(int));
    
    vDesord[0] = 23;
    vDesord[1] = 7;
    vDesord[2] = 49;
    vDesord[3] = 67;
    vDesord[4] = 9;
    vDesord[5] = 2;
    
    for(int i = 0; i < 6; i++){
      cout << " " << vDesord[i];
    }
    
    cout << "\n";
    
    selectionSortOP(vDesord, 6);
    
    for(int i = 0; i < 6; i++){
        cout << vDesord[i] << " ";
    }
    
    
    
    return 0;
}

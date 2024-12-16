#include <iostream>
#include <cstdlib> // Para malloc, calloc e free
using namespace std;

void imprimir(int *v, int tam){
    
    for(int i = 0; i < tam; i++){
        cout << v[i] << " ";
    }
    
    cout<<endl<<endl;
    
}

void SelectionSortIP(int* v, int n) {
    for (int varredura = 0; varredura < n - 1; ++varredura) {
        int iMenor = varredura;

        cout <<  "--- Varredura: " << varredura << " ---" << endl << endl;

        for (int i = varredura + 1; i < n; ++i) {
            if (v[i] < v[iMenor]) {
                iMenor = i;
            }
        }

        cout << "iMenor: " << iMenor << endl;
        
        // Troca os elementos
        int temp = v[iMenor];
        v[iMenor] = v[varredura];
        v[varredura] = temp;

        imprimir(v, n);
        
    }
}

int main() {
    int n = 7; // Número de elementos
    int* v = (int*)calloc(n, sizeof(int)); // Aloca memória para o array

    // Inicializa os elementos
    v[0] = 73; v[1] = 23; v[2] = 89; v[3] = 33;
    v[4] = 1; v[5] = 2; v[6] = 33;

    cout << "Array antes da ordenação: ";
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    SelectionSortIP(v, n);

    cout << "Array após a ordenação: ";
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    free(v); // Libera a memória alocada
    return 0;
}

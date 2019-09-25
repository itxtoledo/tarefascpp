#include <iostream>

using namespace std;

void Merge(int vector[], int ini, int meio, int fim, int vetAux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) && ((dir >= fim) || (vector[esq] < vector[dir]))) {
            vetAux[i] = vector[esq];
            ++esq;
        }
        else {
            vetAux[i] = vector[dir];
            ++dir;
        }
    }
    for (int i = ini; i < fim; ++i) {
        vector[i] = vetAux[i];
    }
}

void MergeSort(int vector[], int inicio, int fim, int vectorAux[]) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    MergeSort(vector, inicio, meio, vectorAux);
    MergeSort(vector, meio, fim, vectorAux);
    Merge(vector, inicio, meio, fim, vectorAux);
}

void MergeSort(int vector[], int tam) {
    int vectorAux[tam];
    MergeSort(vector, 0, tam, vectorAux);
}

int main()
{
    int vector[12] = {1, 7, 2, 10, 2, 5, 4, 11, 6, 13, 20, 15};

    MergeSort(vector,  12);
    for (int i = 0; i < 12; i++)
    {
        cout << vector[i] << ' ';
    }
}
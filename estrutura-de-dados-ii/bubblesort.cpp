#include <iostream>

using namespace std;

int main()
{
    int tamanho = 10;
    int vet[tamanho] = {9, 2, 4, 6, 2, 3, 4, 2, 9, 10};
    int i, j, aux;
    for (i = 0; i < tamanho; i++)
        for (j = 0; j < tamanho; j++)
            if (vet[j] > vet[j + 1])
            {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
    
    for (i = 0; i < tamanho; i++)
    {
        cout << "[" << vet[i] << "]";
    }
}
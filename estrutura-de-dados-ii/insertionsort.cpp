#include <iostream>

using namespace std;

void inserir(int vet[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > key)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}

void mostrar(int vet[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << vet[i] << " ";
    cout << endl;
}

int main()
{
    int vet[] = {9, 1, 4, 3, 5, 2};
    int n = 6;

    inserir(vet, n);
    mostrar(vet, n);
}
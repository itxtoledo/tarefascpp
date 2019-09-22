#include <iostream>

using namespace std;

void quicksort(int arr[], int inicio, int fim)
{
    int i, j, pivo, aux;
    i = inicio;
    j = fim - 1;
    pivo = arr[(inicio + fim) / 2];
    while (i <= j)
    {
        while (arr[i] < pivo && i < fim)
            i++;
        while (arr[j] > pivo && j > inicio)
            j--;
        if (i <= j)
        {
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }
    if (j > inicio)
        quicksort(arr, inicio, j + 1);
    if (i < fim)
        quicksort(arr, i, fim);
}

int main()
{
    int vector[12] = {1, 7, 2, 10, 2, 5, 4, 11, 6, 13, 20, 15};

    quicksort(vector, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << vector[i] << ' ';
    }
}
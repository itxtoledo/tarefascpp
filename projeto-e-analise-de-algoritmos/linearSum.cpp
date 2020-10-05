#include <stdio.h>

int sum(int vetor[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += vetor[i];
    return sum;
}

int main()
{
    int size = 10;
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //55
    printf("Sum: %d", sum(vetor, size));

    return 0;
}

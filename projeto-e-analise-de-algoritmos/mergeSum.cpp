#include <stdio.h>

int sum(int vetor[], int left, int right)
{
    if (left == right)
        return vetor[left];
    int mid = (left + right) / 2;

    int leftSum = sum(vetor, left, mid);
    int rightSum = sum(vetor, mid + 1, right);
    return leftSum + rightSum;
}

int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 55
    printf("Sum: %d", sum(vetor, 0, 9));

    return 0;
}

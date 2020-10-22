#include <iostream>
#include <limits.h>

int max(int a, int b) {
    return (a > b)? a : b;
}

int cutRod(int vetor[], int n)
{
	if (n <= 0)
		return 0;

	int maxVal = INT_MIN;

	for (int i = 1; i <= n; i++)
		maxVal = max(maxVal, vetor[i-1] + cutRod(vetor, n-i));

	return maxVal;
}

int main()
{
	int vetor[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(vetor)/sizeof(vetor[0]);
	std::cout << "Maximum value: " << cutRod(vetor, size);
	return 0;
}

#include <iostream>
#include <limits.h>

int max(int a, int b) {
    return (a > b)? a : b;
}

int bottomUpCutRod(int p[],int n){
    int r[n+1];
    int maxVal;
    
    r[0] = 0;

    for (int j = 1; j <= n; j++)
    {
        maxVal = INT_MIN;
        for (int i = 0; i < j; i++)
            maxVal = max(q,p[i]+r[j-i-1]);
        r[j] = maxVal;
    }

    return r[n];
}

int main()
{
	int vetor[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(vetor)/sizeof(vetor[0]);
	std::cout << "Maximum value: " << bottomUpCutRod(vetor, size);
	return 0;
}

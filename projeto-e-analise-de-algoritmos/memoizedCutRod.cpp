#include <iostream>
#include <limits.h>

int max(int a, int b) {
    return (a > b)? a : b;
}

int memoizedCutRodAux(int p[],int n,int r[]){
    if(r[n] >= 0)
        return r[n];

    int maxVal;

    if(n == 0)
        maxVal = 0;
    else{
        maxVal = INT_MIN;
        for(int i=0;i<n;i++)
            maxVal = max(maxVal,p[i] + memoizedCutRodAux(p,n-i-1,r));
    }
    r[n] = maxVal;
    return maxVal;
}

int memoizedCutRod(int p[],int n){
    int r[n+1];
    for(int i = 0;i<n+1;i++)
        r[i] = INT_MIN;
    return memoizedCutRodAux(p,n,r);
}

int main()
{
	int vetor[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(vetor)/sizeof(vetor[0]);
	std::cout << "Maximum value: " << memoizedCutRod(vetor, size);
	return 0;
}

#include <stdio.h> 
#include <limits.h> 

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h) { 
    int sum = 0; 
    int leftSum = INT_MIN; 

    for (int i = m; i >= l; i--) { 
        sum = sum + arr[i]; 
        if (sum > leftSum) 
          leftSum = sum; 
    } 

    sum = 0; 
    int rightSum = INT_MIN; 

    for (int i = m+1; i <= h; i++) { 
        sum = sum + arr[i]; 
        if (sum > rightSum) 
          rightSum = sum; 
    } 

    return max(leftSum + rightSum, leftSum, rightSum); 
}

int maxSubArraySum(int arr[], int l, int h) { 
    if (l == h) 
    return arr[l]; 
    int m = (l + h)/2; 
    
    return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m+1, h), maxCrossingSum(arr, l, m, h)); 
} 

int main() { 
    int arr[] = { 9, 5, -25, -13, 5, 7, -23, 19, -13, -7, 12, -5, -60, 15, -6, 7 }; 
    int maxSum = maxSubArraySum(arr, 0, sizeof(arr) / sizeof(arr[0]) -1); 
    printf("Maximum subarray %dn", maxSum); 
    return 0; 
}

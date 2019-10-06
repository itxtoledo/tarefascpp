#include <iostream>

using namespace std;

float lagrange(int n, float x[], float y[], float z);

int main()
{
   int n = 3;

   float x[3] = {0.1, 0.6, 0.8};
   float y[3] = {1.221, 3.320, 4.593};

   int z = 0.2;

   cout << lagrange(n, x, y, z);
}

float lagrange(int n, float x[], float y[], float z)
{
   float sum = 0;
   float product = 1;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i != j)
         {
            product *= (z - x[j]) / (x[i] - x[j]);
         }
      }
      sum += y[i] * product;
   }
   return sum;
}
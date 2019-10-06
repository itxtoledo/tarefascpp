#include <iostream>

using namespace std;

int main() {
   int i,j,k; // declare variables and matrixes as input
   float b,x[10];
   float matrix[3][3];
   cout << "\nDigite os elementos da matriz:\n";
   for (i = 0; i < 3; i++){
	   for (j = 0; j < 3; j++){
		   cout<<"["<<i<<"]"<<"["<<j<<"]: ";
		   cin >> matrix[i][j];
	   }
   }

   for(j=0; j<3; j++) {
      for(i=0; i<3; i++) {
         if(i!=j) {
            b=matrix[i][j]/matrix[j][j];
            for(k=0; k<3; k++) { 
               matrix[i][k]=matrix[i][k]-(b*matrix[j][k]);
            }
         }
      }
   }

   cout<<"\nSolução:\n";
   for(i=0; i<3; i++) {
      x[i]=matrix[i][2]/matrix[i][i];
      cout<<"x"<<i << "="<<x[i]<<" ";
   }
}
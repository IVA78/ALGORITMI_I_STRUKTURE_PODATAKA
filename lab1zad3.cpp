#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;

/*
Formula za racunanje pi ->
  𝜋/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
  𝜋 = 4(1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
  𝜋 = 4 * (pow(-1, n + 1) * (1 / n * 2 - 1)) + pi(n - 1)

  
n ce mi odrediti koliko clanova niza uzimam u obzir
npr n = 1 -> 𝜋 = 4
    n = 2 -> 𝜋 = 4 * (1 - 1/3) = 4 * 0.6666666 = 2.666667
*/

double pi (int n) {
   
   
   if(n == 1) {
      return 4 * 1;
   } else {
      return ((4 * (pow(-1, n+1) * (1. / (2 * n - 1)))) + pi(n - 1));
   } 
   
}




int main(void){
   
   int n;
   cout << "Upisite dimenziju polja > ";
   cin >> n;
   double *A = new double[n];

   for(int i = 0; i < n; i++) {
      A[i] = pi(i + 1);
   }
   
   
   cout << "[" << A[0];
   for(int i = 1; i < n; i++) {
      cout << ", " << A[i];
   }
   cout << "]";


   return 0;
}
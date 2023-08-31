#include <stdio.h>
#include <iostream>
#include <math.h>

#define N 5


using namespace std;

double f (double z, int k){

   if(k < 0) {
      return 0;
   }

   if(k == 0) {
      return z;
   }

   return ((-1*pow(z, 2) / ((2*k+1)*(2*k))) * f(z, k-1));
}

int main(void){

   double z = 0.5;
   int k;

   for(int i = 0; i < N; i++) {
      cout << "Upisite vrijednost k > ";
      cin >> k;
      cout << endl << "Rezultat poziva funkcije je > " << f(z,k) << endl;
   }

   /*
   ->Zbog racunanja faktorijela k mora biti >= 0

   Par primjera:
   z = 0.5 k = 0  f = z = 0.5
           k = 1  f = -z^3 / 3! = -0.0208333
           k = 2  f = z^5 / 5! = 0.5^5 / 5! = 0.00026041666
           k = 3  f = -z^7 / 7! = -0.0078125 / 5040 = -0.00000155009

   */

   return 0;
}
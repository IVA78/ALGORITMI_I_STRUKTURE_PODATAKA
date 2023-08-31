#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

double exp (double x, int n, int *fakt, double *xpot){

   if(n == 0) {
      return 1;
   } else {
      int fakt2 = *fakt / n;
      double xpot2 = *xpot / x;
      return ((*(xpot) / *(fakt)) + exp(x, n-1, &fakt2, &xpot2));
   }
}

int main(void){
   
   int n;
   cout << "Upisite dimenziju polja > ";
   cin >> n;

   double x;
   cout << "Upisite x > ";
   cin >> x;

 if(n == 0) {
   cout << "[" << 1 << "]";

 } else {
     double *A = new double[n];
 
   int fakt = 1;
   double xpot = 1;
   for(int i = 0; i < n; i++) {
      if(i > 1) {
         fakt = fakt * i;
      }
      A[i] = exp(x, i, &fakt, &xpot);
      xpot = xpot * x;   
   }
   
   cout << fixed;
   cout << setprecision(6);
   cout << "[" << A[0];
   for(int i = 1; i < n; i++) {
      cout << ", " << A[i];
   }
   cout << "]";
 }


   return 0;
}
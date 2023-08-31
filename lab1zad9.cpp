#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void f (int polje[], int n, int m){

   polje[n-1] = pow(m, n-16);
   if(n == 0) {
      return;
   } else {
      f(polje, n - 1, m);
   }

}

int main(void){

   int n, m;
  cout << "Upisite dimenziju polja n > ";
   cin >> n;

   cout << "Upisite vrijednost m > ";
   cin >> m;

   int *A = new int[n];
   f(A, n, m);

   cout << "[" << A[0];
   for(int i = 1; i < n; i++) {
      cout <<", " <<  A[i];
   }
   cout << "]";

   return 0;
}
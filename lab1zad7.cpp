#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>



using namespace std;

int *nasumicniKvadrati(int *A, int n) {

   int pomPolje[n] = {0};
   int *novo_polje = new int[n];

   srand((unsigned)time(NULL));

   int cnt = 0;
   while(cnt < n) {
      int idx_random = rand() % n;
      if(pomPolje[idx_random] == 0) {
         pomPolje[idx_random] = 1;
         *(novo_polje+cnt) = *(A + idx_random) * *(A + idx_random);
         cnt++;
      }
   }

   return novo_polje;

}

int main(void){

   int n;
   cout << "Upisite dimenziju polja > ";
   cin >> n;
   int *A = new int[n];

   for(int i = 0; i < n; i++) {
      cout << "Upisite " << (i+1) << ". element polja > ";
      cin >> A[i];
   }
   
   
   int *ptr = nasumicniKvadrati(A, n);
   cout << "Polje nakon poziva funkcije > [" << *(ptr);
   for(int i = 1; i < n; i++) {
      cout << ", " << *(ptr + i);
   }
   cout << "]";

   return 0;
}
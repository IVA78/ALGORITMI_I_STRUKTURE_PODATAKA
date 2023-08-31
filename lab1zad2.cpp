#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int zbrojiKvadrate (int polje[], int n) {

   

   if(n > 0) {

      double korijen = sqrt(polje[n - 1]);
   
      if((korijen * korijen) == polje[n - 1] ) {//provjera kvadrata
         return polje[n-1] + zbrojiKvadrate(polje, n-1);
      } else {
         return zbrojiKvadrate(polje, n-1);
      }
   
   

   } 

   return 0;
}

int main(void){
   
   int n;
   cout << "Upisite dimenziju polja > ";
   cin >> n;
   int *A = new int[n];
   
   //punjenje polja
   srand((unsigned)time(NULL));
   for(int i = 0; i < n; i++) {
      A[i] = rand() % 100 + 1;
   }
   
   //ispis polja
   cout << "Polje > [" << A[0];
   for(int i = 1; i < n; i++) {
      cout << ", " << A[i];
   }
   cout <<"]" << endl;

   cout << "Zbroj kvadrata: " << zbrojiKvadrate(A, n) << endl;



   
   return 0;
}
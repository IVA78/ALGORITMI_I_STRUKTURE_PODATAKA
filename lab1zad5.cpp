#include <stdio.h>
#include <iostream>

using namespace std;

//parametrizirana fja, vraca int -> index(-1 ako nema el)
template <typename T> int binarnoTrazi (T polje[], int n, T x){

   int dg = 0;
   int gg = n - 1;
   int middle;

   while(dg <= gg) {
      middle = (dg + gg) / 2;

      if(polje[middle] == x) {
         return middle;
      }

      if(dg >= gg) {
         return -1;
      }

      if(polje[middle] < x) {
         dg = middle + 1;
      }

      if(polje[middle] > x) {
         gg = middle - 1;
      }
   }

   return -1;
}

int main(void){
   
   int n;
   cout << "Upisite dimenziju polja > ";
   cin >> n;

   float x;
   cout << "Upisite x > ";
   cin >> x;
 
   float *A = new float[n];
   
   for(int i = 0; i < n; i++) {
      A[i] = i * 1.1;
   }
   
   cout << "[" << A[0];
   for(int i = 1; i < n; i++) {
      cout << ", "<< A[i];
   }
   cout << "]" << endl;;

   int idx = binarnoTrazi(A, n, x);
   if(idx != -1) {
      cout << "Trazeni element (" << x << ")" << "se nalazi u polju na indeksu " << idx << endl; 
   } else {
      cout << "Trazeni element (" << x << ")" << "se ne nalazi u polju" << endl;
   }

   cout << endl;
 
   int x1;
   cout << "Upisite x > ";
   cin >> x1;

   int *A1 = new int[n];
   for(int i = 0; i < n; i++) {
      A1[i] = i + 3;
   }
   
   cout << "[" << A1[0];
   for(int i = 1; i < n; i++) {
      cout << ", "<< A1[i];
   }
   cout << "]" << endl;

   idx = binarnoTrazi(A1, n, x1);
   if(idx != -1) {
      cout << "Trazeni element (" << x1 << ")" << "se nalazi u polju na indeksu " << idx << endl; 
   } else {
      cout << "Trazeni element (" << x1 << ")" << "se ne nalazi u polju";
   }

   return 0;
}
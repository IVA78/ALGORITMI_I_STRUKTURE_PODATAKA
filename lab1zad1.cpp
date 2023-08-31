#include <stdio.h>
#include <iostream>


using namespace std;

void ispis(float polje[], int n){
   if(n < 1) return;
   ispis(polje, n - 1);
   if(polje[n] < 0) cout << polje[n] << " "; 
}

int main(void){
   
   int n;
   cout << "Upisite dimenziju polja > ";
   cin >> n;
   float *A = new float[n];

   for(int i = 0; i < n; i++) {
      cout << "Upisite " << (i+1) <<". clan polja > " ;
      cin >> A[i];
   }
    
   ispis(A, n);
   return 0;
}
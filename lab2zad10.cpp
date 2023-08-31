#include <iostream>

#define N 8

using namespace std;

void zamijeni(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}

void selection2Sort (int A[], int n, char smjer){


   if(smjer == 0) {

      for(int i = 0; i < n; i++) {
         int min = i;
         for(int j = i + 1; j < n; j++) {
            if(A[j] < A[min]) min = j;
         }
         zamijeni(A[i], A[min]);
      }
   } else {

      for(int i = 0; i < n; i++) {
         int max = i;
         for(int j = i + 1; j < n; j++) {
            if(A[j] > A[max]) max = j;//trazim najmanji
         }
         zamijeni(A[i], A[max]);
      }

   }

}


int main(void) {

   int polje[N];
   for(int i = 0; i < N; i++) {
      cout << "Upisite " << (i+1) << ". element > ";
      cin >> polje[i];
   }
   cout << "Prije: ";
   for(int i = 0; i < N; i++) {
      cout << polje[i] << " ";
   }
   cout << endl;

   int smjer;
   cout << "Upisite smjer sortiranja (0 - uzlazno, 1 -silazno) > ";
   cin >> smjer;

   selection2Sort(polje, N, smjer);
   
   cout << "Nakon: ";
   for(int i = 0; i < N; i++) {
      cout << polje[i] << " ";
   }



   return 0;
}
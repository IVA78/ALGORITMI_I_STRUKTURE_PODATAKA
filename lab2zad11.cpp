#include <iostream>
#include <string.h>

#define N 5

using namespace std;


struct zapis{
   int sifra;
   string naziv;

};

void zamijeni(zapis &a, zapis &b) {
   zapis temp = a;
   a = b;
   b = temp;
}


void obicanBubbleSort (zapis A[], int n, char smjer) {

   if(smjer == 0) {

      for(int i = 0; i < n - 1; i++) {
         for(int j = 0; j < n - 1 - i; j++) {//najveci je dosao do kraja pa ga vise ne gledam
            if(A[j + 1].sifra < A[j].sifra) zamijeni(A[j], A[j+1]);
         }
      }

   } else {

      for(int i = 0; i < n - 1; i++) {
         for(int j = 0; j < n - 1 - i; j++) {
            if(A[j + 1].sifra > A[j].sifra) zamijeni(A[j], A[j+1]);
         }
      }

   }

}

int main(void) {

   zapis zapisi[N];

   for(int i = 0; i < N; i++) {
      cout << "Upisite " << (i+1) << " .sifru > ";
      cin >> zapisi[i].sifra;
      cout << "Upisite naziv jela > ";
      cin >> zapisi[i].naziv;
   }

   int smjer;
   cout << "Upisite smjer sortiranja (0 - uzlazno, 1 -silazno) > ";
   cin >> smjer;

   cout << "Prije: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Sifra: " << zapisi[i].sifra << " Naziv: " << zapisi[i].naziv << endl;
   }
   cout << endl;

   obicanBubbleSort(zapisi, N, smjer);

   cout << "Nakon: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Sifra: " << zapisi[i].sifra << " Naziv: " << zapisi[i].naziv << endl;
   }
   

   return 0;
}
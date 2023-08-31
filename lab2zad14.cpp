#include <iostream>
using namespace std;

#define N 4

void Zamijeni(string *prvi, string *drugi){
  string tmp;
  tmp = *prvi;
  *prvi = *drugi;
  *drugi = tmp;
}

void BubbleSortPoboljsani(string A[], int n, int smjer){

   int i, j;
   bool swapHappened = 1;
   for (i = 0; swapHappened == 1; i++) {
      swapHappened = 0;
      for (j = 0; j < n - 1 - i; j++) {
         if (A[j + 1] < A[j]) {
         Zamijeni(&A[j], &A[j + 1]);
         swapHappened = 1;
         }
      }
   }
}

int main(){

   string stringovi[] = {"Ivo", "Marko", "Juraj", "Pero"};

   cout << "Prije: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Ime: " << stringovi[i] << endl;
   }

   int smjer = 1; //1 uzlazno, 0 silazno

   BubbleSortPoboljsani(stringovi, N, smjer);

   cout << "Nakon: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Ime: " << stringovi[i] << endl;
   }



  return 0;
}
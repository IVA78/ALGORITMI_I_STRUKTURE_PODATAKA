#include <iostream>
#include <time.h>

#define N 5

using namespace std;

struct Cvor {
   double broj;
   Cvor *sljedeci;
};

class Red{

   private:
   Cvor *ulaz;
   Cvor *izlaz;

   public:  
   Red() {
      ulaz = nullptr;
      izlaz = nullptr;
   }

   bool dodaj (double broj) {
      Cvor *novi = new (nothrow) Cvor();
      if(novi == nullptr) return false;

      novi->broj = broj;
      novi->sljedeci = nullptr;

      if(ulaz== nullptr) {
         izlaz = novi;
      } else {
         ulaz->sljedeci = novi;
      }
      ulaz = novi;
      return true;

   }

   bool skini (double *broj) {
      if(izlaz == nullptr) return false;
      Cvor *toDelete = izlaz;
      *broj = izlaz->broj;
      izlaz = izlaz ->sljedeci;

      if(izlaz == nullptr) ulaz = nullptr;
      delete toDelete;

      return true;

   }

   bool poljeURed (int polje[], int n){

      if(n == 0) return true;

      if(dodaj(polje[n-1])) {
         cout << "Dodajem element " << polje[n - 1] << " u red" << endl;
         return poljeURed(polje, n-1);

      } else {
         return false;
      }

   }

};

int main() {
  srand(time(NULL));
  int A[10];
  for (int i = 0; i < 10; i++)
    A[i] = rand() % 10 + 1;
  for (int i = 0; i < 10; i++)
    cout << A[i] << " ";
  cout << "\n";
  Red red;
  red.poljeURed(A, 10);
  return 0;
}
#include <iostream>

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

};

int main(void) {

   Red r;

   double br;
   for(int i = 0; i < N; i++) {
      cout << "Upisite " << (i+1)<< ". broj > ";
      cin >> br;
      r.dodaj(br);
   }

   for(int i = 0; i < N; i++) {
        r.skini(&br);
        cout << br << ", ";
   }





   return 0;
}
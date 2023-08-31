#include <iostream>

#define MAX 5

using namespace std;

class Red {
   private:
   double red[MAX];
   int ulaz, izlaz;

   public:
   Red() {
      ulaz = -1;
      izlaz = -1;
   }
   bool dodaj (double broj){
      if(ulaz == -1 && izlaz == -1) {//red je prazan
         ulaz++;
         izlaz++;
         red[ulaz] = broj;
      } else {
         if(izlaz > (MAX - 1)) return false;
         red[++izlaz] = broj;
         return true;
      }
   }

   bool skini (double *broj) {
      if(ulaz == -1 && izlaz == -1) return false;
      if(ulaz == izlaz) {
         *broj = red[ulaz];
         ulaz = -1;
         izlaz = -1;
         return true;
      }
   
      *broj = red[ulaz];
      ulaz++;
      if(ulaz > (MAX - 1)) ulaz = 0;
      return true;
   }

};

int main(void) {

   Red r;
   double el;

   for(int i = 0; i < MAX; i++) {
      cout << "Upisite " << (i+1) << ".element reda > ";
      cin >> el;
      r.dodaj(el);
   }

   for(int i = 0; i < MAX; i++) {
      r.skini(&el);
      cout << "Brisem " << el << endl;
   }



   return 0;
}
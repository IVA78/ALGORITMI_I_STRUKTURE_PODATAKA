#include <iostream>

#define N 5

using namespace std;

template <class T> class Lista{
   private:

   struct Cvor{
      T element;
      Cvor *sljedeci;
   };

   Cvor *glava;

   public:

   Lista() {
      glava = nullptr;
   }

   bool upis (T element){
      Cvor *novi = new (nothrow) Cvor;

      if(novi == nullptr) return false;

      novi->element = element;
      novi->sljedeci = nullptr;

      if(glava == nullptr || novi->element < glava->element)  {
         novi->sljedeci = glava;
         glava = novi;
      } else {
         Cvor *curr = glava->sljedeci;
         Cvor *prev = glava;
         while(curr != nullptr) {
            if(curr->element > novi->element) break;
            prev = curr;
            curr = curr->sljedeci;
         }

         novi->sljedeci = curr;
         prev->sljedeci = novi;
      }

      return true;
 }
      
   

   void ispis() {
      cout << "GLAVA -> ";
      for(Cvor* curr = glava; curr != nullptr; curr = curr->sljedeci) {
         cout << curr->element << " -> ";
      }
      cout << "KRAJ";
   }

};

int main(void) {

   Lista<int> l;
   int el;

   for(int i = 0; i <= N; i++) {
      cout << "Upisite " << i+1 <<".element liste ";
      cin >> el;
      l.upis(el); 
   }

   l.ispis();

   return 0;
}
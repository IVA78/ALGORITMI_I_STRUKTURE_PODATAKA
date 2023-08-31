#include <iostream>

#define N 5

using namespace std;

template <class T> class Lista{
   private:

   struct Cvor{
      T element;
      Cvor *sljedeci;
      Cvor *prethodni;
   };
 

   Cvor *glava;
   Cvor *rep;

   public:

   Lista() {
      rep = glava = nullptr;
   }

   bool upis (T element){
      Cvor *novi = new (nothrow) Cvor;

      if(novi == nullptr) return false;

      novi->element = element;
      novi->sljedeci = nullptr;
      novi->prethodni = nullptr;

      if(rep == nullptr) {//prazna lista
         glava = novi;
         rep = novi;
      } else {
         rep->sljedeci = novi;
         rep = novi;
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
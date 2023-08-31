#include <iostream>
#include <cstdlib>

#define MAX 100

using namespace std;

class Stog{

   private:
   struct Atom{
      int element;
      Atom *sljedeci;
   };

   Atom *glava;

   public:

   Stog() {
      glava = nullptr;
   }

   ~Stog() {
   }


   bool push(int el) {
      Atom *novi = new (nothrow) Atom;
      if(novi == nullptr) return false;
      novi->element = el;
      novi->sljedeci = glava;
      glava = novi;
      return true;
   }

   void print() {
      cout << "VRH -> ";
      for(Atom *i = glava; i != nullptr; i = i->sljedeci)
         cout << i->element << " -> ";
      cout << "DNO" << endl;
   }



};

int main(void) {

   Stog s;

   for (int i = 0; i < 101; i++){
      int el = rand();
      s.push(el);
   }
        

   s.print();


   return 0;
}
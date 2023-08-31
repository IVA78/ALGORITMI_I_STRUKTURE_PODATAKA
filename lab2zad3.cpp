#include <iostream>
#include <cstdlib>

#define MAX 100

using namespace std;

class Stog{

   private:
   int stog[MAX];
   int vrh;

   public:

   Stog() {
      vrh = -1;
   }

   ~Stog() {
   }


   bool push(int el) {
      if(vrh >= (MAX - 1))return false;
      stog[++vrh] = el;
      return true;
   }

   void print() {
      cout << "VRH -> ";
      for(int i = vrh; i >= 0; i--)
         cout << stog[i] << " -> ";
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
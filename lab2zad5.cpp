#include <iostream>
#include <cstdlib>

#define MAX 10

using namespace std;

class Stog{
   private: 
      int stog[MAX];
      int vrh;
   public:
   Stog() {
      vrh = -1;
   }

   bool push(int el) {
      if(vrh >= (MAX-1)) return false;
      stog[++vrh] = el;
      return true;
   }

   int pop() {
      if(vrh < 0) throw runtime_error("Stog je prazan");

      return stog[vrh--];
      
   }

   void printFromTheBottom() {
      Stog pom;
      cout<<"VRH -> ";
      for(int i = 0; i < MAX; i++) {
         int el = this->pop();
         cout << el << " -> ";
         pom.push(el);
      }
      cout << "DNO" << endl;
      
      cout<<"DNO -> ";
      for(int i = 0; i < MAX; i++) {
         cout << pom.pop() << " -> ";
      }
      cout << "VRH";

   }


};

int main(void) {

   Stog s;
   for(int i = 0; i < MAX; i++) {
      int el = rand() % 10 + 1;
      s.push(el);
   }
   s.printFromTheBottom();


   return 0;
}
#include <iostream>
#include <string>

#define N 5

using namespace std;

class Osoba{

private:

   string ime;
   unsigned short int godine;

 public:
   Osoba() {};

   Osoba(string ime, unsigned short int godine) {
      this->ime = ime;
      this->godine = godine;
   }

   void postaviIme(string ime) {
      this->ime = ime;
   }

   void postaviGodine(unsigned short int godine) {
      this->godine = godine;
   }

   string dohvatiIme() {
      return this->ime;
   }

   unsigned short int dohvatiGodine() {
      return this->godine;
   }

  bool operator<(const Osoba &osoba){
    
    if (osoba.godine > this->godine)
      return true;
    if (osoba.godine < this->godine)
      return false;
    if (osoba.ime > this->ime)
      return true;
    if (osoba.ime < this->ime)
      return false;
  }

   /*
   
   int string::compare (const string& str) const
   Returns:
   0 : if both strings are equal.
   A value < 0 : if *this is shorter than str or,
   first character that doesn't match is smaller than str.
   A value > 0 : if *this is longer than str or,
   first character that doesn't match is greater

*/


};

template <typename T> static void InsertionSort(T A[], int n) {
   int j;
   
    for (int i = 1; i < N; ++i) {
        j = i;
        while (A[j] < A[j-1] && j > 0){
            swap(A[j], A[j-1]);
            j--;
        }
    }
}


int main(void) {

   Osoba polje[] = {{"Ana",20},{"Ivo",9}, {"Marko",9}, {"Lidija",22}, {"Pero",19}};

   cout << "Prije: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Ime: " << polje[i].dohvatiIme() << " Godine: "<< polje[i].dohvatiGodine() << endl;
   }

   InsertionSort(polje, N);

   cout << "Nakon: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Ime: " << polje[i].dohvatiIme() << " Godine: "<< polje[i].dohvatiGodine() << endl;
   }

   return 0;
}
#include <iostream>
using namespace std;

#define N 6

class Vozilo{
private:
  string ime;
  int godina_proizvodnje;

public:
  Vozilo(){};
  Vozilo(string ime, int godina) : ime(ime), godina_proizvodnje(godina){};
  string getIme()
  {
    return ime;
  }
  int getGodinaProizvodnje()
  {
    return godina_proizvodnje;
  }
  void setIme(string ime)
  {
    this->ime = ime;
  }
  void setGodinaProizvodnje(int godina)
  {
    this->godina_proizvodnje = godina;
  }
  bool operator<(const Vozilo &vozilo)
  {
    
    if (this->ime < vozilo.ime)
      return true;
    if (this->ime > vozilo.ime)
      return false;
    if (this->godina_proizvodnje > vozilo.godina_proizvodnje)
      return true;
    if (this->godina_proizvodnje < vozilo.godina_proizvodnje)
      return false;
  }
};

void Zamijeni(Vozilo &prvi, Vozilo &drugi){
  Vozilo pomocni = prvi;
  prvi = drugi;
  drugi = pomocni;
}

void SelectionSort(Vozilo A[], int n){
  int i, j, min;
  for (i = 0; i < n; i++){
    min = i;
    for (j = i + 1; j < n; j++)
      if (A[j] < A[min]){
        min = j;
      }
    Zamijeni(A[i], A[min]);
  }
}

int main(void) {

   Vozilo vozila[] = {{"Pauegot",1981}, {"Pauegot",1983}, {"Ranulet",1967},
{"Fait",1972}, {"BWM",1985}, {"Merdesec",1983}};

cout << "Prije: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Ime: " << vozila[i].getIme() << " Godine: "<< vozila[i].getGodinaProizvodnje() << endl;
   }

   SelectionSort(vozila, N);

   cout << "Nakon: " << endl;
   for(int i = 0; i < N; i++) {
      cout << "Ime: " << vozila[i].getIme() << " Godine: "<< vozila[i].getGodinaProizvodnje() << endl;
   }



   return 0;
}
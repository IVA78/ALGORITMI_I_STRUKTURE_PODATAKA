#include <iostream>
#include <string.h>
using namespace std;

#define N 4

struct Zapis
{
  string ime;
  int p_br;
};

void insertionSort(Zapis A[], int n, char smjer)
{
  Zapis temp;
  int j;
  if (smjer == '0') 
  {
    for (int i = 1; i < n; i++) 
    {
      temp = A[i];
      for (j = i; j >= 1 && A[j - 1].p_br > temp.p_br; j--)
        A[j] = A[j - 1];
      A[j] = temp;
    }
  }
  if (smjer == '1') 
  {
    for (int i = 1; i < n; i++)
    {
      temp = A[i];
      for (j = i; j >= 1 && A[j - 1].p_br < temp.p_br; j--) 
        A[j] = A[j - 1];
      A[j] = temp;
    }
  }
}

int main(void) {

  Zapis zap;
  char smjer;
  cout << "Unesite zapise :\n";
  Zapis zapisi[N];
  for (int i = 0; i < N; i++){
    cout << "Unesite postanski broj: ";
    cin >> zap.p_br;
    cout << "Unesite ime mjesta: ";
    cin >> zap.ime;
    zapisi[i] = zap;
    cout << endl;
  }
  cout << "Unesite smjer(0 ili 1): ";
  cin >> smjer;

  cout << "Prije sortiranja :" << endl;
  for (int i = 0; i < N; i++)
    cout << "Postanski br: " << zapisi[i].p_br << ", Mjesto: " << zapisi[i].ime << endl;

  insertionSort(zapisi, N, smjer);

  cout << "Poslije sortiranja :" << endl;
  for (int i = 0; i < N; i++)
    cout << "Postanski br: " << zapisi[i].p_br << ", Mjesto: " << zapisi[i].ime << endl;

  return 0;
}
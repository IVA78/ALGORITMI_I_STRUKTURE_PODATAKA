#include <stdio.h>
#include <iostream>
#include <string.h>



using namespace std;

char *ostaviSlova (string ulaz){

   int cnt = 0;
   for(int idx = 0; idx < ulaz.length(); idx++) {
      if(ulaz.at(idx) >= 'A' && ulaz.at(idx) <= 'Z' || ulaz.at(idx) >= 'a' && ulaz.at(idx) <= 'z') {
         cnt++;
      }

   }
   
   char *niz = new char[cnt + 1]; // +1 za terminiranje niza

   cnt = 0;
   for(int idx = 0; idx < ulaz.length(); idx++) {
      if(ulaz.at(idx) >= 'A' && ulaz.at(idx) <= 'Z' || ulaz.at(idx) >= 'a' && ulaz.at(idx) <= 'z') {
         niz[cnt] = ulaz.at(idx);
         cnt++;
      }

   }
   niz[cnt] = '\0';

   return niz;
}

int main(void){

   string ulaz = "asp12_i_ASP13";
   cout << ostaviSlova(ulaz) << endl;

   return 0;
}
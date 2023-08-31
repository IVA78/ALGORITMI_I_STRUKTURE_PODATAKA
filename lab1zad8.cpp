#include <stdio.h>
#include <iostream>

using namespace std;

class SanitizedString{
   private:

      string str;

   public:

      SanitizedString(){}

       SanitizedString(string str) {
          this->str = str;
       }

       ~SanitizedString() {
          cout << "Unistavam objekt " << str;
       }

       void removeDuplicateWhitespace() {
         for(int i = 0; i < str.size(); i++) {
            if(str.at(i) == ' ' && str.at(i + 1) == ' ') {
               str.erase(i,1);
               i--;
            }
         }
       }
       
       void removeNonAlphaChars() {
         for(int i = 0; i < str.size(); i++) {
            if(!(str.at(i) >= 'a' && str.at(i) <= 'z' || str.at(i) >= 'A' && str.at(i) <= 'Z') ) {
               str.erase(i,1);
               i--;
            }
         }

       }

       string getStr() {
         return str;
       }

       void setStr(string str) {
         this->str = str;
       }

       friend ostream& operator<<(ostream &left, const SanitizedString& right);

};

ostream& operator<<(ostream &left, const SanitizedString& right) {
         left << right.str;
         return left;
}


int main(void){

   string str;
   cout << "Upisite zeljeni niz znakova > ";
   getline(cin, str);
   cout << "Pocetni niz znakova > " << str << endl;

   SanitizedString sanStr(str);
   sanStr.removeDuplicateWhitespace();
   cout << "Niz nakon 1. funkcije > " << sanStr << endl;
   sanStr.removeNonAlphaChars();
   cout << "Niz nakon 2. funkcije > " << sanStr << endl;




   return 0;
}
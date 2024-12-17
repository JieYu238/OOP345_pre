#include<iostream>
using namespace std;
union CID{  //same piece of memory for three differenct purpose
   double a;   //cannot use back
   int b;
   char c[8];
};
struct scid {
   double a;
   int b;
   char c[7];
};
int main() {
   cout << sizeof(CID) << endl;
   cout << sizeof(scid) << endl;
   CID i;
   i.a = 1234.567;
   cout << i.a << endl;
   i.b = 987;
   cout << i.b << endl;
   for (int n = 0; n < 6; n++) {
      i.c[n] = 'x';
   }
   i.c[6] = 0;
   cout << i.c << endl;
   cout << i.a << endl; //2.05882, does not make sense
   /*i.c[0] = '1';
   i.c[1] = '2';
   i.c[2] = '3';
   i.c[3] = '4';
   i.c[4] = '5';
   cout << i.c << endl;*/

   return 0;
}
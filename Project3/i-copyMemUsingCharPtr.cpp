#include <iostream>
using namespace std;

void copyMem(char* des, const char* src, size_t size) {
   for (size_t i = 0; i < size; i++) {
      des[i] = src[i];
   }
}

int main() {

   double a = 1234.56789;
   double b;
   copyMem((char*)&b, (const char*)&a, sizeof(double));
   cout << b << endl;


   //int* p;
   //double* q;
   //cout << sizeof(p) << " " << sizeof(q) << endl;  //same, both addresses are 8 bytes
   //cout << sizeof(*p) << " " << sizeof(*q) << endl;
   return 0;
}

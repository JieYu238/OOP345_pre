#include <iostream>
using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
   T c;
   c = a;
   a = b;
   b = c;
}

int main() {

   double a = 3.4;
   double b = 5.6;
   char c = 'A';
   char d = 'B';
   mySwap(a, b);
   cout << "After swapping: a = " << a << " b = " << b << endl;
   mySwap(c, d);
   cout << "After swapping: c = " << c << " d = " << d << endl;
   return 0;
}

#include <iostream>
using namespace std;

template<class T>
void faa(T a) {
   cout << a << endl;
}

template<typename T> //template header
void foo() {
   /*T value;
   value = 1.5;*/
   T value = static_cast<T>(1.5);
   cout << value << '\n';
}


void swap(double& a, double& b) {
   double c;
   c = a;
   a = b;
   b = c;
}

int main() {
   faa("Jie");
   faa(42);

   foo<double>();
   foo<int>();
   foo<string>();

   //foo(); Error: T cannot be deduced for foo;
   //faa(); Error: No argument to deduce 'T'

   double a = 3.4;
   double b = 5.6;
   char c = 'A';
   char d = 'B';
   swap(a, b);
   cout << "After swapping: a = " << a << " b = " << b << endl;
   swap(c, d);
   cout << "After swapping: c = " << c << " d = " << d << endl;
   return 0;
}

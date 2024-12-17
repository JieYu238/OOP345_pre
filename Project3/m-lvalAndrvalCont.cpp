#include <iostream>
using namespace std;

void display(int& a) {  //lvalue
   a = 77;
   cout << "lvalue: " << a << endl;
}
void display(int&& a) { //rvalue
   cout << "rvalue: " << a << endl;
}

int main() {
   int i = 10;
   display(i);
   display(123);
   return 0;
}
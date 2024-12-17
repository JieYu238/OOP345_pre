#include<iostream>
using namespace std;

int main() {
   int a[5]{ 10, 20, 30, 40, 50 };
   for (int& elm : a) { // range based loop
      cout << elm << endl;
   }
   cout << endl;
   for (auto& el : a) {
      cout << el << endl;
   }
   return 0;
}
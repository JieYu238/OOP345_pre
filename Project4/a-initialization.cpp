#include<iostream>
using namespace std;
class Coord {
   int m_x, m_y;
public:
   Coord(int x, int y) :m_y{y} {
      m_x = x;
   }
};
int main() {
   int a = 5;
   int b{ 5 }; //{} only used in initialization
   int c = { 5 };
   int d{};
   int e[400]{};
   double f[4]{ 1, 2.3, 3, 5.9 };
   Coord C{ 10, 45 };

   cout << a << " " << b << " " << c << " " << d << endl;
   for (int i = 0; i < 4; i++) {
      cout << f[i] << " ";
   }
   cout << endl;
   return 0;
}
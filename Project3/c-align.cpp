#include <iostream>
using namespace std;

/*
sizeof tells how much space a type or variable will occupy in memory.
alignof tells how the type should be aligned in memory.
*/

/*
data type         size
int               4 bytes (32 bits)
double            8 bytes(64 bits)
float             4 bytes(32 bits)
long              4 bytes(32 bits) or 8 bytes(64 bits)
char              1 bytes(8 bits)
long long         8 bytes(64 bits)

*/
struct Coord {
   double x, y;
};
struct CoordId {
   double x, y;
   long long val;
   char id;
};
struct test {  // 8+8+8 = 24 bytes
   char c;
   double d;
   int i;
};
struct test2 { //8+4+1+3 = 16 bytes
   double d;
   int i;
   char c;
};
struct test3 {
   char c;
   int i;
   double d;
};
int main() {
   int a = 197520;
   double* p = (double*)197520;
   int* q = (int*)197520;
   short* r = (short*)197520;
   Coord* c = (Coord*)197520;
   a++;
   cout << "a: " << a << endl;
   p++;
   q++;
   r++;
   c++;
   cout << "p: " << (unsigned)p << endl;
   cout << "q: " << reinterpret_cast<unsigned long long>(q) << endl;
   cout << "r: " << reinterpret_cast<unsigned long long>(r) << endl;
   cout << "c: " << reinterpret_cast<unsigned long long>(c) << endl;
   cout << alignof(Coord) << endl;
   cout << "size of Coord:" << sizeof(Coord) << endl;
   cout << "alignmet of coord: " << alignof(Coord) << endl;
   cout << "double: " << sizeof(double) << endl;
   cout << "double: " << sizeof(double) << endl;
   cout << "double: " << sizeof(long long) << endl;
   cout << "double: " << sizeof(char) << endl;
   cout << "size of CoordId:" << sizeof(CoordId) << endl;
   cout << "alignmet of coordId: " << alignof(CoordId) << endl;
   cout << sizeof(test) << endl;
   cout << sizeof(test2) << endl;
   return 0;
}
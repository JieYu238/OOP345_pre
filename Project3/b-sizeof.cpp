#include <iostream>
using namespace std;

/*
padding happens to satisfy alignment requirements for each member and ensure the structure's total size is aligned to the largest member's alignment.
to make it satisfied that ()+()+()
and () = 8 as a groupB

char     1+7
double   8
int      4+4

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
      cout << "size of Coord " << sizeof(Coord) << endl; //16

      /*
      
      it should be : 8+8+8+1 = 25bytes
      but because of padding and alignment
      mn
      Offset	      Member	      Size	      Notes
      0	            double x	        8	   No padding needed.
      8	            double y	        8	   No padding needed.
      16	         long long val	     8	   No padding needed.
      24	            char id	        1	Padding added (7 bytes) to make the size a multiple of 8.
      
      Total size: 8+8+8+1+7 = 32bytes
      */

      cout << "size of CoordId " << sizeof(CoordId) << endl;  //32, padding and alignment

      cout << "size of test " << sizeof(test) << endl;  //24
      cout << "size of test2 " << sizeof(test2) << endl; //16
      cout << "size of test3 " << sizeof(test2) << endl; //16

      cout << "size of short " << sizeof(short) << endl; //2
   return 0;
}
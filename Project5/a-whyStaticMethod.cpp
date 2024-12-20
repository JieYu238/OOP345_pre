#include <iostream>
using namespace std;
constexpr char nl = '\n';
class {
   bool m_trace = false;
public:
   auto& trace(bool value) {
      m_trace = value;
      return *this;
   }
   auto& operator<<(const char* message) {
      if (m_trace) cout << (message ? message : "(NULLstr)");
      return *this;
   }
   auto& operator<<(int val) {
      if (m_trace) cout << val;
      return *this;
   }
   auto& operator<<(double val) {
      if (m_trace) cout << val;
      return *this;
   }
   auto& operator<<(char ch) {
      if (m_trace) cout << ch;
      return *this;
   }
} tracer;

constexpr int ReadBufferSize = 80;
class Cstr {
public:
   //using static keyword make it no instance required, just call class::method
   static void cpy(char* des, const char* src) {
      while (*des++ = *src++); // strcpy (fix for gcc on linux)
   }
   static int len(const char* str) {
      const char* end = str;
      while (*end++);
      return static_cast<int>(end - str) - 1;
   }
   static void allocNcpy(char*& des, const char* src) {
      des = new char[len(src) + 1];
      cpy(des, src);
   }
   static char* read(istream& is) { // reading any size of Cstr dynamically and return it
      char* data = new char[ReadBufferSize];
      char* str = data;
      int noOfBuffers = 1;
      bool done;
      do {
         done = true;
         cin.getline(str, ReadBufferSize, '\n'); // if cin fails, it means entry was greater than 50 chars
         if (cin.fail()) {
            noOfBuffers++;  // keep track of number of buffers to add
            char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1]; // allocate bigger memory
            Cstr::cpy(temp, data); // copy the already read test into temp
            delete[] data;  // delete the old (too short) memory
            data = temp;    // point to newly large allocated memory 
            str = data + (ReadBufferSize - 1) * (noOfBuffers - 1); // set the read pointer to continue reading the rest of text
            cin.clear();   // clear cin to read again
            done = false;  //we are not done yet
         }
      } while (!done);   // go back and continue reading if not done
      allocNcpy(str, data);
      delete[] data;
      return str;
   }

};

class Name {
private:
   char* m_value{};
   static int m_noOfObj;
public:
   static int noOfObj() {
      return m_noOfObj;
   }
   Name(const char* value = nullptr) {
      if (value) {
         Cstr::allocNcpy(m_value, value);
      }
      tracer << "Create " << m_value << nl;
   }
   Name(const Name& N) {
      m_noOfObj++;
      tracer << "Copy " << N.m_value << nl << "  using: ";
      operator=(N);
   }
   Name(Name&& N) {  // move copyconstructor
      tracer << "(move copy) Take ownership of " << N.m_value << " in a new Name" << nl << "  by calling: ";
      operator=(move(N));
   }
   Name& operator=(Name&& N) { // move assignment 
      if (this != &N) {
         tracer << " Move assign " << N.m_value << " to " << m_value << " by assignment" << nl;
         delete[] m_value;
         m_value = N.m_value;
         N.m_value = nullptr;
      }
      return *this;
   }
   Name& operator=(const Name& N) {
      if (this != &N) {
         tracer << "Assign " << m_value << " to " << N.m_value << nl;
         delete[] m_value;
         Cstr::allocNcpy(m_value, N.m_value);
      }
      return *this;
   }
   ~Name() {
      m_noOfObj--;
      tracer << "Remove " << m_value << " from memory" << nl;
      delete[] m_value;
   }
   ostream& print(ostream& os = cout)const {
      return os << (m_value ? m_value : "(Nullstr)");
   }
   istream& read(istream& is = cin) {
      delete[] m_value;
      m_value = Cstr::read(is);
      return is;
   }
};
int Name::m_noOfObj = 0;

ostream& operator<< (ostream& os, const Name& N) {
   return N.print(os);
}
istream& operator>> (istream& is, Name& N) {
   return N.read(is);
}

int main() {
   Name A;
   tracer.trace(true);
   cout << "Name: ";
   tracer << "cin >> A;" << nl;
   cin >> A;
   cout << "Hello " << A << endl;
   tracer << "Name B = A;" << nl;
   Name B = move(A);
   cout << "B: " << B << endl;
   tracer << "A = \"Jack\";" << nl;
   A = "Jack";
   cout << "A: " << A << endl;
   tracer << "A = B;" << nl;
   A = move(B);
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   cout << "We have " << Name::noOfObj() << " names in this program!" << endl;
   return 0;
}

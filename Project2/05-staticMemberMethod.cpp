#include<iostream>
using namespace std;
class Num {
	int value;
	static int s;
public:
	Num(int val = 0): value{val}{
		s++;
		cout << "Object Number " << s << " is created!" << endl;
	}
	void print() {
		cout << noOfInstances() << ": " << value << endl;
	}
	static int noOfInstances() { //static method can not access non-static method or attribute, but can access static members
		/*cout << value << endl;*/
		return s;
	}
	~Num() {
		s--;
	}
};
int Num::s = 0;
void foo() {
	Num n[10];
	cout << Num::noOfInstances() << endl;
}
int main() {
	Num N(10), M(20);
	N.print();
	M.print();
	cout << N.noOfInstances() << endl;
	foo();
	return 0;
}


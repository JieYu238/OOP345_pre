#include<iostream>
using namespace std;

void faa();
void foo();

int main() {
	cout << "OOP345" << endl;
	foo();
	cout << "end of foo" << endl;
	for (int i = 0; i < 10; i++) {
		faa();
	}
	cout << endl;
	return 0;
}

//						static int a = 1							int a = 1
//scope					local to the function or file			local to the function
//lifetime				entire program execution				limited to block execution
//initialization		only once(retains value across calls)	re-initialzed every time
//access in other files	No(internal linkage if global)			Yes(external linkage if global)

void faa() {
	static int a = 1; 
	a++;
	cout << a << " ";
}

void foo() {
	int a = 10;
	while (a--) {
		cout << a << " ";
	}
	cout << endl;
}
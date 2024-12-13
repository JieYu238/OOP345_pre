#include <iostream>
#include "Student.h"
using namespace std;

int main() {
	cout << "Hello OOP345NBB" << endl;
	int mark = 60;	//function scope
	int i;
	cout << MinPassGrade << endl;
	cout << ">";
	cin >> i;
	if (i < 0) {
		int i = 4;	//block scope
		cout << "i is assigned to :" << i;
	}
	else {
		cout << "i is equal to :" << i;
	}
	return 0;
}
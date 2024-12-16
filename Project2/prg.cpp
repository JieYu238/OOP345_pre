#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Name {
	char* m_data{};
	//char*& data is a reference to a pointer
	/*private static method*/
	static void alloCopy(char*& data, const char* src) {	//it is needed in name for logic purposes but not action related to a "Name"
		delete[] data;
		data = new char[strlen(src) + 1];
		strcpy(data, src);
	}
public:
	Name(const char* name) {
		alloCopy(m_data, name);
	}
	void display()const {
		cout << m_data << endl;
	}
};
int main(int argc, char* argv[], char* env[]) {

	return 0;
}


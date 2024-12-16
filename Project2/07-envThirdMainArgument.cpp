#include<iostream>
using namespace std;
//project2		this is a test

/*
argc stands for "argument count"
argv stands for "argument vector"
env stands for "environment variables"

this allows us to access to command-line arguments and environment variables
*/
int main(int argc, char* argv[], char* env[]) {
	for (int i = 0; env[i]; i++) {
		cout << i+1 << "- " << env[i]<< endl;
	}
	return 0;
}


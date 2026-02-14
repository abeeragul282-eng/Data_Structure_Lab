#include<iostream>
using namespace std;
int main() {
	char* ch = new char;
	cout << "Enter a character:" << endl;
	cin >> *ch;
	cout << "Stored Character:" << *ch << endl;
	delete ch;
	ch = nullptr;
	system("pause");
}
#include<iostream>
using namespace std;
struct Product {
	string name;
	int code;
	float price;
};
int main() {
	int a;
	cout << "Enter number of products:" << endl;
	cin >> a;
	Product* p = new Product[a];
	for (int i = 0; i < a; i++) {
		cout << "***Product" << i + 1<<"***" << endl;
		cout << "Name:";
		cin >> p[i].name;
		cout << "Code:";
		cin >> p[i].code;
		cout << "Price:";
		cin >> p[i].price;
	}
	cout << "^^^Products Details^^^" << endl;
	for (int i = 0; i < a; i++) {
		cout << "Name:" << p[i].name <<"|"<<" Code:" << p[i].code <<"|" << " Price : " << p[i].price << endl;
	}
	delete[]p;
	p = nullptr;
	system("pause");
}
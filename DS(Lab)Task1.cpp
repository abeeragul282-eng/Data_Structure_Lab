#include<iostream>
using namespace std;
int main() {
	int arr[5] = { 10,20,30,35,40 };
	int* ptr = arr;
	for (int i = 0; i < 5; i++) {
		cout << *ptr << endl;
		ptr++;
	}
	return 0;
}
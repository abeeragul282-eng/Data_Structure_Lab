#include<iostream>
using namespace std;
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int x = 5, y = 6;
	cout << "Before Swap:" << endl;
	cout << "x=" << x<<"\n" << "y=" << y << endl;
	swap(&x, &y);
	cout << "After Swap:" << endl;
	cout << "x=" << x<<"\n" << "y=" << y << endl;
	return 0;
}
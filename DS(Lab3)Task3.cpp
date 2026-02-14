#include<iostream>
using namespace std;
int main() {
    int r, c;
    cout << "Enter number of rows:" << endl;
    cin >> r;
    cout << "Enter number of columns:" << endl;
    cin >> c;
    int** matrix = new int* [r];
    for (int i = 0; i < r; i++) {
        matrix[i] = new int[c];
    }
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "^^Matrix^^" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    system("pause");
}

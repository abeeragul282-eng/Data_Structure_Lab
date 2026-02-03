#include <iostream>
using namespace std;

int main() {
    int n, search;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[50];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> search;
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            cout << "Element found at index: " << i;
            return 0;
        }
    }
    cout << "Element not found";
    return 0;
}

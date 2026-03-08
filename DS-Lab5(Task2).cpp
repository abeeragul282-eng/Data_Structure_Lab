#include<iostream>
using namespace std;
class Node {
public:
    int rain;
    Node* prev;
    Node* next;
    Node(int r) {
        rain = r;
        prev = NULL;
        next = NULL;
    }
};
class RainList {
private:
    Node* head;
public:
    RainList() {
        head = NULL;
    }
    void insert(int r) {
        Node* newNode = new Node(r);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void display() {
        Node* temp = head;
        int total = 0;
        int count = 0;
        int max = 0;
        int min = 100000;
        while (temp != NULL) {
            cout << temp->rain << " ";
            total += temp->rain;
            if (temp->rain > max)
                max = temp->rain;
            if (temp->rain < min)
                min = temp->rain;
            count++;
            temp = temp->next;
        }
        cout << "\nTotal Rainfall = " << total;
        cout << "\nAverage Rainfall = " << (float)total / count;
        cout << "\nHighest Rainfall = " << max;
        cout << "\nLowest Rainfall = " << min;
    }
    void rainfallAfter5() {
        Node* temp = head;
        int count = 1;
        while (temp != NULL) {
            if (count == 6) {
                cout << "\nRainfall after 5th node = " << temp->rain;
                return;
            }
            temp = temp->next;
            count++;
        }
    }
};
int main() {
    RainList r;
    int x;
    cout << "Enter rainfall for 7 days\n";
    for (int i = 0; i < 7; i++) {
        cin >> x;
        if (x < 0) {
            cout << "Negative not allowed\n";
            i--;
            continue;
        }
        r.insert(x);
    }
    r.display();
    r.rainfallAfter5();
}
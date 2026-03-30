#include<iostream>
using namespace std;
class Node {
public:
    string title;
    float price;
    int edition;
    int pages;
    Node* next;
    Node(string t, float p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
        next = NULL;
    }
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    void push(string t, float p, int e, int pg) {
        Node* newNode = new Node(t, p, e, pg);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Book removed from stack\n";
    }
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "\nTop Book:\n";
        cout << "Title: " << top->title << endl;
        cout << "Price: " << top->price << endl;
        cout << "Edition: " << top->edition << endl;
        cout << "Pages: " << top->pages << endl;
    }
    void display() {
        Node* temp = top;
        if (temp == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "\nRemaining Books:\n";
        while (temp != NULL) {
            cout << "------------------\n";
            cout << "Title: " << temp->title << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Edition: " << temp->edition << endl;
            cout << "Pages: " << temp->pages << endl;

            temp = temp->next;
        }
    }
};
int main() {
    Stack s;
    s.push("Book1", 500, 1, 200);
    s.push("Book2", 600, 2, 250);
    s.push("Book3", 700, 1, 300);
    s.push("Book4", 800, 3, 350);
    s.push("Book5", 900, 2, 400);
    s.peek();
    s.pop();
    s.pop();
    s.display();
    return 0;
}
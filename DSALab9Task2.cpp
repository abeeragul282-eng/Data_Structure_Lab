#include<iostream>
using namespace std;
class Node {
public:
    int id;
    Node* next;
    Node(int i) {
        id = i;
        next = NULL;
    }
};
class Queue {
public:
    Node* front;
    Node* rear;
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int id) {
        Node* newNode = new Node(id);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class Stack {
public:
    Node* top;
    Stack() {
        top = NULL;
    }
    void push(int id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }
    void pop(int id) {
        if (top == NULL) {
            cout << "Garage empty\n";
            return;
        }
        if (top->id != id) {
            cout << "Truck is not near garage door\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Truck exited\n";
    }
    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Queue road;
    Stack garage;
    road.enqueue(1);
    road.enqueue(2);
    road.enqueue(3);
    cout << "Road: ";
    road.display();
    garage.push(1);
    garage.push(2);
    garage.push(3);
    cout << "Garage: ";
    garage.display();
    garage.pop(3);
    garage.pop(1);
}
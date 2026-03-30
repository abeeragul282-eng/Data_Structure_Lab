#include<iostream>
using namespace std;
class Node {
public:
    int id;
    float height, weight, vision;
    string status;
    Node* next;
    Node* prev;
    Node(int i, float h, float w, float v, string s) {
        id = i;
        height = h;
        weight = w;
        vision = v;
        status = s;
        next = NULL;
        prev = NULL;
    }
};
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int i, float h, float w, float v, string s) {
        Node* newNode = new Node(i, h, w, v, s);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Line empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        delete temp;
    }
    void removeSecond() {
        if (front == NULL || front->next == NULL) {
            cout << "Not enough applicants\n";
            return;
        }
        Node* second = front->next;
        front->next = second->next;
        if (second->next != NULL)
            second->next->prev = front;
        delete second;
        cout << "2nd applicant removed\n";
    }
    void display() {
        Node* temp = front;

        while (temp != NULL) {
            cout << "ID: " << temp->id << " Status: " << temp->status << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Queue q;
    for (int i = 1; i <= 7; i++) {
        q.enqueue(i, 5.5, 60, 1.0, "Waiting");
    }
    cout << "Initial Line:\n";
    q.display();
    q.removeSecond();
    cout << "\nAfter removing 2nd:\n";
    q.display();
    q.dequeue();
    cout << "\nAfter first leaves:\n";
    q.display();
}
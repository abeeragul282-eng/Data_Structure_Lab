#include<iostream>
using namespace std;
class Node {
public:
    int marks;
    Node* prev;
    Node* next;
    Node(int m) {
        marks = m;
        prev = NULL;
        next = NULL;
    }
};
class DLL {
private:
    Node* head;
public:
    DLL() {
        head = NULL;
    }
    void addBeginning(int m) {
        Node* newNode = new Node(m);
        if (head != NULL) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }
    void addAfter45(int m) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->marks == 45) {
                Node* newNode = new Node(m);
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL)
                    temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "45 not found\n";
    }
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List Empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }
    void deleteAfter45() {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->marks == 45 && temp->next != NULL) {
                Node* del = temp->next;
                temp->next = del->next;
                if (del->next != NULL)
                    del->next->prev = temp;
                delete del;
                return;
            }
            temp = temp->next;
        }
        cout << "45 not found\n";
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->marks << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    DLL d;
    d.addBeginning(30);
    d.addBeginning(45);
    d.addBeginning(60);
    d.display();
    d.addAfter45(50);
    d.display();
    d.deleteBeginning();
    d.display();
    d.deleteAfter45();
    d.display();
}
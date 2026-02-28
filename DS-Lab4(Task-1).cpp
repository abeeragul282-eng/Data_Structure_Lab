#include <iostream>
using namespace std;
class Mobile {
public:
    string name;
    int unitsOnHand;
    double price;
    Mobile(string n, int u, double p) {
        name = n;
        unitsOnHand = u;
        price = p;
    }
};
class Node {
public:
    Mobile data;
    Node* next;

    Node(Mobile m) : data(m) {
        next = NULL;
    }
};
class Store {
private:
    Node* head;
public:
    Store() {
        head = NULL;
    }
    void insertAtStart(Mobile m) {
        Node* newNode = new Node(m);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(Mobile m) {
        Node* newNode = new Node(m);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void deleteMobile(string name) {
        if (head == NULL) return;
        if (head->data.name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            if (temp->next->data.name == name) {
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
                return;
            }
            temp = temp->next;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Brand: " << temp->data.name << endl;
            cout << "Units: " << temp->data.unitsOnHand << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^" << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Store s;
    s.insertAtStart(Mobile("Xiaomi", 10, 50000));
    s.insertAtEnd(Mobile("Apple", 5, 150000));
    s.insertAtEnd(Mobile("OPPO", 20, 30000));
    cout << "All Mobiles:\n";
    s.display();
    cout << "\nAfter Deleting Xiaomi:\n";
    s.deleteMobile("Xiaomi");
    s.display();
    system("pause");
}
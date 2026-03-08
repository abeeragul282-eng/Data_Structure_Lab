#include<iostream>
using namespace std;
class Node {
public:
    string name;
    int score;
    Node* prev;
    Node* next;

    Node(string n, int s) {
        name = n;
        score = s;
        prev = NULL;
        next = NULL;
    }
};
class Golf {
private:
    Node* head;
public:
    Golf() {
        head = NULL;
    }
    void addPlayer(string n, int s) {
        Node* newNode = new Node(n, s);
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
        while (temp != NULL) {
            cout << temp->name << " " << temp->score << endl;
            temp = temp->next;
        }
    }
    void deletePlayer(string n) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == n) {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Player not found\n";
    }
    void lowestScore() {
        Node* temp = head;
        int min = 100000;
        while (temp != NULL) {
            if (temp->score < min)
                min = temp->score;
            temp = temp->next;
        }
        cout << "Lowest Score = " << min;
    }
    void sameScore(int s) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->score == s)
                cout << temp->name << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Golf g;
    g.addPlayer("Abeera", 90);
    g.addPlayer("Sofia", 80);
    g.addPlayer("Abdullah", 90);
    g.display();
    cout << "\nPlayers with score: 70\n";
    g.sameScore(70);
    cout << "\nLowest Score:\n";
    g.lowestScore();
}
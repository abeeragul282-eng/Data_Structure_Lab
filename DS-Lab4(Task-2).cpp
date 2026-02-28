#include <iostream>
using namespace std;

class Profile {
public:
    int id;
    string name, gender, email, interest, dob;
    int age;
    Profile(int i, string n, string g, int a, string e, string in, string d) {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }
};
class Node {
public:
    Profile data;
    Node* next;

    Node(Profile p) : data(p) {
        next = NULL;
    }
};
class Portal {
private:
    Node* head;
public:
    Portal() {
        head = NULL;
    }
    void insertProfile(Profile p) {
        Node* newNode = new Node(p);
        newNode->next = head;
        head = newNode;
    }
    void updateProfile(int id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.id == id) {
                cout << "Enter New Name: ";
                cin >> temp->data.name;
                cout << "Enter New Gender: ";
                cin >> temp->data.gender;
                cout << "Enter New Age: ";
                cin >> temp->data.age;
                cout << "Enter New Email: ";
                cin >> temp->data.email;
                cout << "Enter New Interest: ";
                cin >> temp->data.interest;
                cout << "Enter New DOB: ";
                cin >> temp->data.dob;
                cout << "Profile Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Profile Not Found!\n";
    }
    void deleteProfile(string name) {
        if (head == NULL) return;
        if (head->data.name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Profile Deleted!\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            if (temp->next->data.name == name) {
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
                cout << "Profile Deleted!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Profile Not Found!\n";
    }
    void searchProfile(string name) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.name == name) {
                cout << "Profile Found!\n";
                cout << "ID: " << temp->data.id << endl;
                cout << "Name: " << temp->data.name << endl;
                cout << "Gender: " << temp->data.gender << endl;
                cout << "Age: " << temp->data.age << endl;
                cout << "Email: " << temp->data.email << endl;
                cout << "Interest: " << temp->data.interest << endl;
                cout << "DOB: " << temp->data.dob << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Profile Not Found!\n";
    }
    void display() {
        Node* temp = head;
        if (head == NULL) {
            cout << "No Profiles Available!\n";
            return;
        }
        while (temp != NULL) {
            cout << "---------------------------\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Gender: " << temp->data.gender << endl;
            cout << "Age: " << temp->data.age << endl;
            cout << "Email: " << temp->data.email << endl;
            cout << "Interest: " << temp->data.interest << endl;
            cout << "DOB: " << temp->data.dob << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Portal p;
    int choice;
    do {
        cout << "\n***SOCIAL MEDIA PORTAL***\n";
        cout << "1. Add Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. Display All Profiles\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1) {
            int id, age;
            string name, gender, email, interest, dob;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Gender: "; cin >> gender;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Email: "; cin >> email;
            cout << "Enter Interest: "; cin >> interest;
            cout << "Enter DOB: "; cin >> dob;
            p.insertProfile(Profile(id, name, gender, age, email, interest, dob));
            cout << "Profile Added Successfully!\n";
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to Update: ";
            cin >> id;
            p.updateProfile(id);
        }
        else if (choice == 3) {
            string name;
            cout << "Enter Name to Delete: ";
            cin >> name;
            p.deleteProfile(name);
        }
        else if (choice == 4) {
            string name;
            cout << "Enter Name to Search: ";
            cin >> name;
            p.searchProfile(name);
        }
        else if (choice == 5) {
            p.display();
        }
    } while (choice != 6);
    cout << "Program Ended.\n";
    return 0;
}
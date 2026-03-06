#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function prototypes
void insertMenu();
void deleteMenu();
void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAfterNode(int key, int value);
void insertBeforeNode(int key, int value);
void deleteFirst();
void deleteLast();
void deleteSpecific(int key);
void deleteAfterNode(int key);
void deleteBeforeNode(int key);
void displayList();
///////////////////////////////////////////////////////////////////////////////////
int main() {
    int choice;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display List\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertMenu(); break;
            case 2: deleteMenu(); break;
            case 3: displayList(); break;
            case 4: return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
    return 1;
}

// -------- Insertion Menu ----------
void insertMenu() {
    int choice, value, key;
    cout << "\n--- Insertion Menu ---\n";
    cout << "1. Insert at Beginning\n2. Insert at End\n";
    cout << "3. Insert After a Node\n4. Insert Before a Node\n5. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter the key after which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            insertAfterNode(key, value);
            break;
        case 4:
            cout << "Enter the key before which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            insertBeforeNode(key, value);
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice! Try again.\n";
    }
}

// -------- Deletion Menu ----------
void deleteMenu() {
    int choice, key;
    cout << "\n--- Deletion Menu ---\n";
    cout << "1. Delete First Node\n2. Delete Last Node\n3. Delete Specific Node\n";
    cout << "4. Delete After a Node\n5. Delete Before a Node\n6. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: deleteFirst(); break;
        case 2: deleteLast(); break;
        case 3:
            cout << "Enter the key to delete: ";
            cin >> key;
            deleteSpecific(key);
            break;
        case 4:
            cout << "Enter the key after which to delete: ";
            cin >> key;
            deleteAfterNode(key);
            break;
        case 5:
            cout << "Enter the key before which to delete: ";
            cin >> key;
            deleteBeforeNode(key);
            break;
        case 6: return;
        default: cout << "Invalid choice! Try again.\n";
    }
}

// -------- Insertion Functions --------
void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " inserted at the beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    cout << value << " inserted at the end.\n";
}

void insertAfterNode(int key, int value) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << value << " inserted after " << key << ".\n";
}

void insertBeforeNode(int key, int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        insertAtBeginning(value);
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;
    cout << value << " inserted before " << key << ".\n";
}

// -------- Deletion Functions --------
void deleteFirst() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted node with value " << temp->data << ".\n";
    delete temp;
}

void deleteLast() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        cout << "Deleted node with value " << head->data << ".\n";
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    cout << "Deleted node with value " << temp->data << ".\n";
    delete temp;
}

void deleteSpecific(int key) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        deleteFirst();
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }
    prev->next = temp->next;
    cout << "Deleted node with value " << temp->data << ".\n";
    delete temp;
}

void deleteAfterNode(int key) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp || !temp->next) {
        cout << "No node exists after " << key << " to delete.\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    cout << "Deleted node with value " << delNode->data << " after " << key << ".\n";
    delete delNode;
}

void deleteBeforeNode(int key) {
    if (!head || head->data == key) {
        cout << "No node exists before " << key << " to delete.\n";
        return;
    }
    if (head->next && head->next->data == key) {
        deleteFirst();
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;
    while (next && next->data != key) {
        prev = curr;
        curr = next;
        next = next->next;
    }
    if (!next) {
        cout << "No node exists before " << key << " to delete.\n";
        return;
    }
    prev->next = next;
    cout << "Deleted node with value " << curr->data << " before " << key << ".\n";
    delete curr;
}

// -------- Display Function --------
void displayList() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Current List: ";
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

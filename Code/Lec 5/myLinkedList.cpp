#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;


void displayInsertManue();
void displayLinkedList();
void displayDeleteManue();

void insertAtBegining(int val);
void insertAtEnd(int val);
void insertAfter(int key, int val);
void insertBefore(int key, int val);

void deleteAtBegin();
void deleteAtEnd();
void deleteAfter(int key);
void deleteBefore(int key);


int main()
{
    while (true)
    {
        
        cout << "--Linked List -- \n";
        cout << "1. Insert Vale\n";
        cout << "2. Delete value\n";
        cout << "3. Display Linked List\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayInsertManue();
            break;
        case 2:
            displayDeleteManue();
            break;
        case 3:
            displayLinkedList();
            break;
        case 4:
            return -1;break;
        default:
            cout << "Exiting form the main " << endl;
        };
    }
    return 0;
}

// function definations
void displayInsertManue()
{
    std::system("clear"); 
    int val;
    int myKey = 0;
    cout << "1. Insert at Begining. " << endl;
    cout << "2. Insert at End." << endl;
    cout << "3. Insert after a Node: " << endl;
    cout << "4. Insert before a Node: " << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter value to insert ";
        cin >> val;
        insertAtBegining(val);
        break;
    case 2:
        cout << "Enter a value to insert: ";
        cin >> val;
        insertAtEnd(val);
        break;
    case 3: 
        cout << "Enter a value to insert: ";
        cin >> val;
        cout << "Enter a key ";
        cin >> myKey;
        insertAfter(myKey, val);
        break;
    case 4: 
        cout << "Enter a value to insert: ";
        cin >> val;
        cout << "Enter a key ";
        cin >> myKey;
        insertBefore(myKey, val);
        break;
    default:
        cout << "Exiting";
        break;
    };
}

void displayDeleteManue()
{
    cout << "1. Delete at Begining. " << endl;
    cout << "2. Delete at End." << endl;
    cout << "3. Delete after a Node: " << endl;
    cout << "4. Delete before a Node: " << endl;
    int choice;
    cin >> choice;
    int key = -1;
    switch (choice)
    {
    case 1:
        deleteAtBegin();
        break;
    case 2:
        deleteAtEnd();
        break;
    case 3:
    
    cout << "Delete key.." << endl;
    cin >> key;
        deleteAfter(key);
        break;
    case 4:
        cout << "Enter key to delete before" << endl;
        cin >> key;
        deleteBefore(key);
        break;
    default:
        break;
    };
}

void displayLinkedList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtBegining(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val)
{
    if (!head)
    {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        head = newNode;
        return ;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    temp->next = newNode;
}

void insertAfter(int key, int val)
{
    if (!head)
        return;
    Node* temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "404!! Key Not found..." << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(int key, int val)
{
    if (!head)
    {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        head = newNode;
        return;
    }
    Node* previous = NULL;
    Node* temp = head;
    while (temp->data != key)
    {
        previous = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "404!! Key Not found..." << endl;
        return;
    } 
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = temp;
    previous->next = newNode;

}


void deleteAtBegin()
{
    if (!head)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }
    head= head->next;
    cout << "First Element of the linked List deleted. " << endl;
}

void deleteAtEnd()
{
    if (!head)
    {
        cout << "Linked List is Empty!!" << endl;
        return;
    }
    if (!head->next)
    {
        head = NULL;
        return;
    }
    Node* prev = NULL;
    Node* temp = head;
    while(temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    cout << "Last Element of the Linked List Deleted." << endl;
}
   

void deleteAfter(int key)
{
    if (!head)
    {
        cout << "Linked List is Empty. Can not delete " << endl;
        return ;
    }
    if (head->next == NULL)
    {
        cout << "Single Element. Can not Delete" << endl;
        return;
    }
    Node* temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
    }
    if (temp->next)
    {
        temp->next = temp->next->next;
        delete temp->next;
    }
    
    
}

void deleteBefore(int key)
{
    if (!head)
    {
    cout << "Linked list is Empty. Cannot delete."<< endl;
    return;
    }

    if (head->data == key)
    {
    cout << "Cannot delete before head element."<< endl;
    return;
    }
    Node* prev = NULL;
    Node* temp = head;
    while (temp->next && temp->next->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (!temp->next)
    {
        cout << "Key not found." << endl;
        return;
    }
    if (prev == NULL) 
    {
    head = temp->next;
    delete temp;
    }
    else
    {
        prev->next = temp->next;
        delete temp;
    }
}
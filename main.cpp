// COMSC-210 | Lab 17 | Adriel Chandra
// IDE used: Visual Studio Code

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node *);
void addNodeHead (Node *, int);
void addNodeTail (Node *, int);
void deleteNode (Node *, int);
void insertNode (Node *, int, int);
void deleteList (Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addNodeHead (head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output (head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode (head, entry);
    output (head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output (head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode (head, entry, 10000);
    output (head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

// Output the nodes
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// Insert a node to the head
void addNodeHead (Node * head, int tmp_val){
    Node *newVal = new Node;
        
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = tmp_val;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = head;
        newVal->value = tmp_val;
        head = newVal;
    }
}

// Insert a node to the tail
void addNodeTail (Node * head, int tmp_val){
    Node *newVal = new Node;
    newVal->value = tmp_val;
    newVal->next = nullptr;

    if (!head) { // if empty list, it's the new head
        head = newVal;
    } else { // if this is the last node, it's now the new last node
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newVal;
    }
}

// Delete a node
void deleteNode (Node * head, int position){
    Node * current = head;
    output(head);

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (position - 1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}

// Insert a node
void insertNode (Node * head, int position, int value){
    Node * current = head;
    Node * prev = head;

    // traverse that many times
    for (int i = 0; i < (position); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
}

// Delete the entire list
void deleteList (Node * head){
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
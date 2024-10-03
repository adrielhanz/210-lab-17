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
void addNodeHead ();
void addNodeTail ();
void deleteNode ();
void insertNode ();
void deleteList ();

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        addNodeHead (head, rand() % 100);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode ();
    output (head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
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
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
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
void addNodeHead (){
    Node *newVal = new Node;
        
    // adds node at head
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
void addNodeTail (){

}

// Delete a node
void deleteNode (){
    Node * current = head;
    output(head);

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
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
void insertNode (){

}

// Delete the entire list
void deleteList ();
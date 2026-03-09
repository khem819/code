#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) { 
            head = tail = newNode;
        } else { 
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyList ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.print();  

    return 0;
}

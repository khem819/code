#include<iostream>
#include<queue>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class QueueLL {
Node* head;
Node* tail;
public:
    QueueLL() {
        head = nullptr;
        tail = nullptr; 
}

void push(int data){ //insert at tail
    Node* newNode = new Node(data);
    if(tail == nullptr){ //empty queue
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;

}

void pop(){ //delete from head
    if(head == nullptr){ //empty queue
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if(head == nullptr){ //if queue becomes empty
        tail = nullptr;
    }
    delete temp;
} 

int front(){ //return front element
    if(head == nullptr){
        cout<<"Queue is empty"<<endl;
        return -1; //indicating empty queue
    }
    return head->data;
} 

bool empty(){ //check if queue is empty
    return head == nullptr;
}
};


int main() {
    QueueLL q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Output: 10

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20

    q.pop();
    q.pop();
    q.pop(); // Attempt to pop from empty queue

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}

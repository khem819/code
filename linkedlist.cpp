#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
       List(){
          head=tail=NULL;
       }

void push_back(int val){
    Node* newNode= new Node(val);

    if(head==NULL){
        head=tail=newNode;
    }else{
        tail->next=newNode;
        tail=newNode;
    }
}


void push_front(int val){
    Node* Newnode= new Node(val);

    if(head==NULL){
        head=tail=Newnode;
        return;
    }else{
        Newnode->next=head;
        head=Newnode;
    }
}

void pop_front(){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
    }
void pop_back(){
    if(head==NULL){
        return ;
    }
    Node* temp=head;
    while (temp->next!=tail){
      temp=temp->next;
    }
    temp->next=NULL;
    delete tail;
    tail=temp;
} 

     void printlist(){
    Node* temp=head;
    while (temp !=NULL)
    {
        cout<<temp->data<<"-";
        temp=temp->next;
        
    }
    cout<<"NULL"<<endl;    
    } 
};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);     
    ll.push_front(6);

    ll.printlist();
    
    ll.push_back(4);
    ll.pop_front();

     ll.printlist();
    ll.pop_back();

     ll.printlist();

   

    return 0;
};

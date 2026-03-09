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

class circularlist{
    Node* head;
    Node* tail;

    public:
    circularlist(){
        head=tail=NULL;
    }
    void inserathead(int val){
        Node* newnode=new Node(val);

        if(tail==NULL){
            head=tail=newnode;
            tail->next=head;
        }else{
            newnode->next=head;
            head=newnode;
            tail->next=head;   //insertathead
            // tail->next=newnode;
            // tail=newnode;         //inserattail
        }
    }
    void print(){
        if(head==NULL) return;
        cout<<head->data<<"->";
        // Node* temp=head->next;
        Node* temp=head->next;
      
        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }

    void deletionathead(){
        if(head==NULL) return;

        if(head==tail){
            delete head;
            head=tail=NULL;  
        }else{
        // Node* temp=head;
        Node* temp=tail;
        Node* prev=head;
        // head=head->next;
        // tail->next=head;
        while(prev->next!=tail){
             prev=prev->next;
             tail=prev;
             tail->next=head;
             temp->next=NULL;
             delete temp;
        }

        // temp->next=head;
        // delete temp;
        }
    }
};

int main(){
    circularlist cl;
    cl.inserathead(1);
    cl.inserathead(2);
    cl.inserathead(3);
     cl.print();

    cl.deletionathead();
    cl.print();

    cl.deletionathead();
    cl.print();


   
    return 0;
}

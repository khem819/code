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

void insert(int val,int pos){
    if(pos<0){
        cout<<"invalid position\n";
        return;
    }
    if(pos==0){
        push_front(val);
        return;
    }

    Node* temp=head;

    for(int i=0;i<pos-1;i++){
        if(temp==NULL){
            cout<<"invalid pos\n";
        }
        temp=temp->next;
    }

    Node* newNode=new Node(val);
    newNode->next=temp->next;
    temp->next=newNode;
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

int search(int key){
    Node* temp=head;
    int idx=0;

    while(temp !=NULL){
        if(temp->data==key){
            return idx;
        }
        temp=temp->next;
        idx++;
    }
    return -1;
}    
};

int main(){
    List ll;
    ll.push_front(2);
    ll.push_front(6);
    ll.push_front(1);
    ll.insert(4,0);
    ll.printlist();

    cout<<ll.search(2)<<endl;

    return 0;
};

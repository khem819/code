#include<iostream>
using namespace std;

#define SIZE 5

class circularqueue{
    int arr[SIZE];
    int front,rear;

    public:
    circularqueue(){
        front=rear=-1;
    }

    void enqueue(int val){
        if((front==0 && rear==SIZE-1)||(rear+1==front)){
            cout<<"queue is overflow";
            return ;
        }
        if(front==-1){
            front=rear=0;
        }
        else if(rear=SIZE-1 && front!=0){
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=val;
    }
    
}
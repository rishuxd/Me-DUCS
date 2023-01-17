#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;
        cout<<"Memory free for node "<<value<<endl;
    }
};

class Dequeue{
    public:
    Node* front;
    Node* back;

    Dequeue(){
        front=NULL;
        back=NULL;
    }

    void push_front(int data){
        Node* temp = new Node(data);
        if(front==NULL){
            front = temp;
            back = temp;
        }
        else{
            temp->next=front;
            front=temp;
        }
    }

    void push_back(int data){
        Node* temp = new Node(data);
        if(front==NULL){
            front = temp;   
        }
        else{
            back->next = temp;  
        }
        back = temp;
    }

    void pop_back(){
        if(front==NULL){
            cout<<"Deque underflow."<<endl;
            return;
        }
        Node* nodetopop;
        if(front==back){
            nodetopop=front;
            front=NULL;
            back=NULL;
        }
        else{
            Node* temp = front;
            while(temp->next != back){
                temp=temp->next;
            }
            nodetopop=back;
            temp->next=NULL;
            back=temp;
        }
        free(nodetopop);
        return;
    }

    void pop_front(){
        if(front==NULL){
            cout<<"Deque underflow."<<endl;
            return;
        }
        Node* nodetopop;
        if(front==back){
            nodetopop=front;
            front=NULL;
            back=NULL;
        }
        else{
            nodetopop=front;
            front=front->next;
        }
        free(nodetopop);
        return;
    }

    void display(){
        Node* temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }
};

int main(){
    Dequeue deq;
    deq.push_front(11);
    deq.display();
    deq.push_front(12);
    deq.display();
    deq.push_back(13);
    deq.display();

    deq.pop_front();
    deq.display();
    deq.pop_back();
    deq.display();
    return 0;
}
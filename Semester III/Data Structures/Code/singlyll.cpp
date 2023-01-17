#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        cout << "Memory is free for the node with data " << value << " ." << endl;
    }
};

void insertAtHead(Node *&head, int data){
    Node *temp = new Node(data);
    if (head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void insertAtPosition(Node* head, int data, int position){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* curr = head;
    int cnt = 1;
    while(cnt < position-1){
        curr=curr->next;
        cnt++;
    }

    Node* temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        head=head->next;
        temp->next==NULL;
        delete temp;
        return;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

Node* searchElement(Node* &head, int el){
    Node* temp = head;
    while(temp->data != el){
        temp = temp->next;
    }
    return temp;
}

void concatenate(Node* &head1, Node* &head2){
    Node* temp = head1;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = head2;
    head2 = head1;
}

void display(Node *&head)
{
    Node *temp = head;
    cout<<"Head: "<<temp->data<<endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = NULL;
    Node *head1 = NULL;

    insertAtHead(head, 5);
    display(head);

    insertAtHead(head, 16);
    display(head);

    insertAtHead(head, 86);
    display(head);

    insertAtPosition(head, 42, 3);
    display(head);

    cout<<"Pointer of 42: "<<searchElement(head, 42)<<endl;

    deleteNode(head, 1);
    display(head);

    deleteNode(head, 3);
    display(head);

    insertAtHead(head1, 400);
    display(head1);
    insertAtHead(head1, 600);
    display(head1);
    insertAtHead(head1, 800);
    display(head1);

    concatenate(head, head1);
    display(head);
    display(head1);
}
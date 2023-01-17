#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* prev;

    Node(int val)
    {
        data = val;
    }
    
};

void print(Node *&head)
{
    Node *temp = head;
    cout<<"Transversal in forward direction \n";
    while(temp->next != head){
        cout << temp->data << " <--> ";
        temp=temp->next;
    }
    cout<<temp->data<< endl;

    cout<<"\nTransversal in backward direction \n";
    Node* last = head->prev;
    temp = last;
    while(temp->prev != last){
        cout << temp->data << " <--> ";
        temp=temp->prev;
    }
    cout<<temp->data<< endl;
}

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        temp->next = temp->prev = temp;
        return;
    }
    Node *last = head->prev;

    temp->next = head;
    temp->prev = last;
    last->next = head->prev = temp;

    head = temp;
}

void insertAtPosition(Node *&head, int val, int pos)
{

    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }
    Node *cur = head;
    Node *temp = new Node(val);
    int x = 0;
    do{
        cur = cur->next;
        x++;
    }while (x < pos - 1 );

    Node * next = cur->next;
    cur->next = temp;
    temp->prev = cur;
    temp->next = next;
    next->prev = temp;
}

void insertAtTail(Node*&head,int val){
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
    }
    Node* last = head->prev;

    temp->next = head;
    temp->prev = last;
    last->next = temp;
    head->prev = temp;
}

void deleteHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *cur = head;
    head = head->next;
    head->prev = cur->prev;
    cur->prev->next = head;
    delete cur;
}

void deleteAtPosition(Node *&head, int pos)
{
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    Node *temp = head;
    if( pos == 1){
        deleteHead(head);
        return;
    }
    
    int k = 0;
    Node *prevNode;
    do{
        k++;
        temp = temp->next;
    }while( k < pos-1 );

    if(temp == head){
        deleteHead(head);
        return;
    }
    
    prevNode->next = temp->next;
    temp->next->prev = prevNode;

    delete temp;
}

void deleteTail(Node*&head){
    if(head == NULL)
        return;

    if(head->next == head ){
        delete head;
        return;
    }

    Node* prevNode = head->prev->prev;
    
    Node* temp = prevNode->next;
    prevNode->next = head;
    head->prev = prevNode;
    delete temp;
}

int search(Node *head, int key)
{
    Node *cur = head;
    int x = 0;
    do
    {
        if (cur->data == key)
            return x;
        cur = cur->next;
        x++;
    }while (cur!= head);
    return -1;
}

Node *&concatenate(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *cur = head1;
    Node *cur2 = head2;
    
    head1->prev->next = head2;
    head2->prev = head1->prev;

    cur->prev = cur2->prev;
    cur2->next = cur;
    
    return head1;
}

int main()
{

    Node *sll = NULL;
    insertAtHead(sll, 1);
    insertAtHead(sll, 0);
    insertAtHead(sll, -2);
    insertAtHead(sll, -3);
    insertAtPosition(sll, -1, 2);
    insertAtTail(sll,2);
    insertAtTail(sll,3);

    cout << "LL1 :\n";
    print(sll);

    deleteHead(sll);
    deleteAtPosition(sll, 1);
    deleteTail(sll);
    cout << "\nUpdated LL1 :\n";
    print(sll);

    int res = search(sll, 0);
    if (res != -1)
        cout << "\nThe element is found at pos " << res << endl;
    else
        cout << "\nNot Found\n";

    Node *sll2 = NULL;
    insertAtHead(sll2, -1);
    insertAtHead(sll2, -2);
    insertAtHead(sll2, -3);
    insertAtPosition(sll2, -5, 2);
    cout << "\nLL2 :\n";
    print(sll2);

    Node *head = concatenate(sll, sll2);
    cout << "\nConcatenated LL : \n";
    print(head);
}
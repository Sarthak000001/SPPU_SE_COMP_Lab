#include <iostream>
//#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    explicit Node(int d)
    {
        this->data = d;
        next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        while (this->next != NULL)
        {
            delete next;
            next = NULL;
            cout << "memory is released" << endl;
        }
        cout << "Memory is delete for the Node with value " << val << endl;
    }
};

void InsertNode(Node* &tail, int element, int d)
{
    //   assuming the element is present in the list
    if (tail == NULL)
    {
        // when the list is empty
        Node *newNode = new Node(d);
        newNode->next = newNode; //making it circular
        tail = newNode;
    }
    else
    {
        // when the list is not empty
        // and assuming the element is present in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // Element is found -> curr is representing the element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node* &tail,int element){
    if(tail == NULL){
        cout << "List is Empty " << endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != element){
            prev = curr;
            curr = curr->next;
        }
        //curr represent the node that we won't to delete
        if(curr == prev){
            tail = NULL;
        }
        if(curr == tail){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&tail)
{
    Node *temp = tail;
    if(tail == NULL){
        cout << "List is empty " << endl;
        return ;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);

    cout << endl;
}
//! -----------------------------------------------------------------
bool isCircular(Node* head){
    if(head == NULL){
        return true;
    }
    else{
        Node* temp = head->next;
        while(temp != NULL && temp != head){
            temp = temp->next;
        }
        if(temp == head){
            return true;
        }
        return false;
    }
}
int main()
{
    // Node* tail = NULL;
    Node *tail = NULL;
    InsertNode(tail, 1, 5);
    print(tail);
    InsertNode(tail, 5, 10);
    print(tail);
    InsertNode(tail, 5, 8);
    print(tail);
    InsertNode(tail, 10, 15);
    print(tail);
    InsertNode(tail, 15, 30);
    print(tail);
    
    // deleteNode(tail,5);
    // print(tail);
    if(isCircular(tail)){
        cout << "Linked List is Circular " << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    cout << "tail : " << tail->data << endl;
   
    return 0;
}
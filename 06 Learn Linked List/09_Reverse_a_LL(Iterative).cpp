#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* reverseLL(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
    Node*front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
    }
    return prev;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    cout<<"Orignal Linked List is: ";
    print(head);
    cout<<endl;
    cout<<"Reversed Linked List is: ";
    head=reverseLL(head);
    print(head);
    return 0;
}
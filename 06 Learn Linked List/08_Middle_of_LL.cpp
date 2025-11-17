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
Node* midOfLL(Node* head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void print(Node* head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head=new Node(3);
    head->next=new Node(8);
    head->next->next=new Node(7);
    head->next->next->next=new Node(1);
    head->next->next->next->next=new Node(3);
    cout<<"Orignal List is: ";
    print(head);
    cout<<endl;
    Node* res=midOfLL(head);
    cout<<"Middle of Linked List is: "<<res->data<<endl;

}
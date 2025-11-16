#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* insertNode(Node* head,int val){
    if(head==NULL){
        return NULL;
    }
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->back=head->next;
    cout<<"Orignal List: ";
    print(head);
    cout<<endl;
    cout<<"Linked List after insertion of head: ";
    head=insertNode(head,10);
    print(head);
    return 0;
}
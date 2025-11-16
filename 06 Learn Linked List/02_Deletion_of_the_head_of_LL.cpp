#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* deleteHead(Node* head){
    if(head==NULL){
       return NULL;
    } 
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
void printList(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    cout<<"Orignal List: ";
    printList(head);
    cout<<endl;
    cout<<"List after deletion of head of LL is: ";
    head=deleteHead(head);
    printList(head);
    return 0;
}
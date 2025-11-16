#include<bits/stdc++.h>
#include <chrono>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,int next1,int back1){
        int data=data1;
        int next=next1;
        int back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* reverseDLL(Node* head){
   if(head==NULL || head->next==NULL){
        return head; 
    }
    Node* last=NULL;  
    Node* current=head;   
    while(current!=NULL){
        last=current->back; 
        current->back=current->next; 
        current->next=last;         
        current = current->back; 
    }
    return last->back;
}
void print(Node* head){
    if(head==NULL) return;
    Node* current=head;
    while(current!=NULL){
        cout<<current->data<< " ";
        current=current->next;
    }
}
int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->back=head->next;
    cout<<"Orignal List is: ";
    print(head);
    cout<<endl;
    cout<<"Reverse Linked List is: ";
    head=reverseDLL(head);
    print(head);
    return 0;
}
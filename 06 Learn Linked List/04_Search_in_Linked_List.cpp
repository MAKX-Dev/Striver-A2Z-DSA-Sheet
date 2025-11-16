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
bool searchKey(Node* head,int key){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key) return true;
        temp=temp->next;
    }
    return false;
}
void printList(Node* head){
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
    cout<<"oringnal Linked list is: ";
    printList(head);
    cout<<endl;
    int key=3;
    bool res=searchKey(head,key);
    cout<<res<<endl;
}
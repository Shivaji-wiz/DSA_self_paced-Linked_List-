#include<bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node *next;
   Node *prev;
   Node(int x){
       data = x;
       next = NULL;
       prev = NULL;
   }
};

Node *insertend(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

Node *reverseDLL(Node *head){
    if(head==NULL || head->next == NULL)return head;

    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

void printlist(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
    int n,b;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>b;
        head  = insertend(head,b);

    }

    printlist(head);
    cout<<endl;
    head = reverseDLL(head);
    printlist(head);
}

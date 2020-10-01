#include<iostream>
using namespace std;
class Node{
    public:
    data;
   Node *next;
   Node(int data){
       this->data=data;
       next=NULL;
   }
};
Node* takeInputBetter(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head=newNode;
            tail = newNode;
        }
        else{
            tail->next=newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
Node* deleteNode(Node *head,int i){
    if(head == NULL){
        return head;
    }
if(i==1){
    return head->next;
}
Node* temp = head;
int count =1;
while(temp!=NULL && count<i-1){
    temp = temp->next;
    count++;
}
if(temp!= NULL){
    Node *a = temp->next;

if(a!=NULL){
    Node *b = a->next;
    temp->next =b;
    delete a;
}
}
return head;
}
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    Node* head = takeInputBetter();
    int i;
    cout<<"Enter the position to be deleted"<<" ";
    cin>>i;
    head = deleteNode(head,i);
    print(head);
    
}

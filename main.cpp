#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next ;

    node(int n){
        data = n;
        next = NULL;
    }
};

void push( node*& head , int data){

    if(head == NULL){
        node* newnode = new node(data);
        head = newnode;
        head->next = newnode;
    }

    else{

        node* newnode = new node(data);
        node* ptr = head;

        while(ptr->next != head)
        ptr = ptr->next;

        ptr->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void print(node* head){

    node* temp = head ;

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
}

void deletenodefirst(node*& head){

if(head == NULL){
    cout<<"circualr linklist us empty "<<endl;
    return ;
}

if(head->next == head){

    delete(head);
    // head=NULL;
}

  else{
    
    node* ptr = head;
    node* temp = head ;

    
    while(ptr->next != head)
    ptr = ptr->next;

    
    head = head->next;
    ptr->next = head;

    delete(temp);
}
}

void deletenodelast(node*& head ){

node* temp = head;
node* pre = NULL;

while(temp->next != head){
    pre = temp;
    temp = temp->next;
}

pre->next = head;

}

void deletenodeatnode(node*& head , int key ){

node* temp = head;
node* pre = NULL;

while(temp->data != key){
    pre = temp;
    temp = temp->next;
}

pre->next = temp->next;
delete(temp);

}

int main (){

node* head = NULL;

push(head, 2);
push(head , 4);
push(head , 6);
push(head , 7);
push(head , 63);
push(head , 41);
push(head , 74);
print(head);
cout<<"after the delete"<<endl;

deletenodefirst(head);
print(head);
cout<<endl;
deletenodelast(head);
print(head);
cout<<endl;
deletenodeatnode(head , 63);
print(head);
cout<<endl;

}
#include<iostream>
#include<vector>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
    
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            
            delete next;
            this -> next = NULL;
        }
        
        cout << "memory is free for data: " << value << endl;
    }
};


void insertAtHead(Node* &head, int data){
    
    //create new node
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    
    //create new node
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, int position, int data){
    
   
    //create new node
    Node* nodeToInsert = new Node(data);
    Node* temp = head;
    
     if(position == 1){
        insertAtHead(head, data);
        return;
    }
    
    if(temp -> next == NULL){
        insertAtTail(head, data);
        return;
    }
    
    
    while(position - 1){
      temp = temp -> next;
      position--;
    }
    
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
  
}

void print(Node* &head){
     
     Node* temp = head;
     
     while(temp != NULL){
         cout << temp -> data << " ";
         temp = temp -> next;
     }
     cout << endl;
}

void deleteAtPosition(Node* &head, Node* &tail, int position){
    
    //if deleting first position element
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }else{
        
    Node* curr = head;
    Node* prev = NULL;
    
    while(position-1){
        prev = curr;
        curr = curr -> next;
        position--;
    }
    
    //if deleting last position element
    if(curr -> next == NULL){
       tail = prev;
    }
    
    prev -> next = curr -> next;
    
    curr -> next = NULL;
    
    delete curr;
    }
   
}

int main(){
    
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;
    
    
    
    insertAtHead(head, 20);
    
    print(head);
    
    insertAtHead(head, 14);
    
    print(head);
    
    insertAtTail(tail, 30);
    
    print(head);
    
    insertAtTail(tail, 80);
    print(head);
    
    insertAtPosition(head, 1, 40);
    
    print(head);
    
    deleteAtPosition(head, tail, 6);
    print(head);
    
    insertAtTail(tail, 43);
    print(head);
    
    
    return 0;
}

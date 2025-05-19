#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    
    ~Node(){
        int val = this -> data;
        cout << "Memory freed for data: " << val << endl;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head; 
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;  
        }
    }
    
    void insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            newNode -> next = head;
        }else{
            tail -> next = newNode;
            tail = newNode;
            tail -> next = head;
        }
    }
    
    void insertAtPosition(int position, int data){
        
        if(position == 0){
            insertAtHead(data);
            return;
        }
        
        Node* temp = head;
        
        while(position - 1){
            temp = temp -> next;
            position--;
        }
        if(temp -> next == head){
            insertAtTail(data);
            return;
        }
        
        Node* newNode = new Node(data);
        Node* current = temp -> next;
        temp -> next = newNode;
        newNode -> next = current;
    }
    
    void deleteAtPosition(int position){
      
       if(head == nullptr) return;
        
        if(position == 1){
            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node* temp = head;
            head = head -> next;
            tail -> next = head;
            delete temp;
            return;
        }else{
            Node* curr = head;
            Node* prev = nullptr;
            while(position - 1 && curr -> next != head){
                prev = curr;
                curr = curr -> next;
                position--;
            }
            
            if(curr -> next == head){
                prev -> next = head;
                delete curr;
                return;
            }
            
            prev -> next = curr -> next;
            curr -> next = nullptr;
            delete curr;
            
        }
   
    }

    void printTwice() {
        if (head == nullptr) return;

        Node* current = head;
        int count = 0;

        do {
            cout << current->data << " ";
            current = current->next;
            if (current == head) count++;
        } while (count < 2);

        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.insertAtHead(30);
    cll.insertAtHead(40);
    cll.insertAtTail(70);
    cll.insertAtTail(80);
    cll.insertAtPosition(2, 90);
    cll.printTwice();
    cll.deleteAtPosition(3);
    cll.printTwice();

    return 0;
}


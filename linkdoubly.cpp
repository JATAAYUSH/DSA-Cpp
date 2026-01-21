#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node (int val){
        data = val;
        next = prev = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == NULL) {
            head = tail = newnode;
        }else{
            newnode -> next = head;
            head -> prev = newnode;
            head = newnode;
        }
    }
    void push_back(int val){
        Node* newnode = new Node(val);
        if(head == NULL) {
            head = tail = newnode;
        }else{
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
        }
    }
    void pop_front(){
        if(head == NULL) return;
        else{
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
    }
    void pop_back(){
        if(head == NULL) return;
        else{
            Node* temp = tail;
            tail = tail -> prev;
            // if(tail != NULL){
                tail -> next = NULL;
            // }
            temp -> prev == NULL;
            delete temp;
        }
    }
    void printdll(){
        Node* temp = head;
        while(temp != NULL){
            cout<< "|"<<temp->data<<"|"<< " <==> ";
            temp = temp-> next;
        }
        cout<< "NULL\n";
    }
};
int main(){
    List dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(4);
    dll.push_back(5);
    dll.push_back(6);
    dll.pop_front();
    dll.pop_back();
    dll.printdll();

}

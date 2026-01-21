#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
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
        if(tail == NULL){
            head = tail = newnode;
            tail->next = head;
        }else{
            newnode -> next = head;
            head = newnode;
            tail->next = head;
        }
    }
    void print(){
        if(head == NULL) return;
        cout<< head->data <<" --> ";
        Node* temp = head->next;
        while (temp!=head){
            cout<< temp -> data<<" --> ";
            temp = temp -> next;
        } 
        cout<<temp->data<<endl;       
    }
};

int main(){
    List cl;
    cl.push_front(3);
    cl.push_front(2);
    cl.push_front(1);
    cl.print();
    return 0;
}
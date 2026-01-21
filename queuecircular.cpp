#include <iostream>

using namespace std;
class CircularQueue{
    int* arr;
    int currsize,cap;
    int f,r;

public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap];
        currsize = 0;
        f = 0;
        r = -1;
    }

    void push(int data){
        if(currsize == cap){
            cout<<"Queue is full :-";
        }else{
            r = (r+1) % cap;
            arr[r] = data;
            currsize++;
        }
    }

    void pop(){
        if(empty()) {
            cout<<"Queue is Empty :-";
            return;
        }else{
            f = (f+1)% cap;
            currsize--;
        }
    }

    int front(){
        if(empty()) {
            cout<<"Queue is Empty :-";
            return -1;
        } else{
            return arr[f];
        }
    }

    bool empty(){
        return currsize == 0;
    }

    void print(){
        for(int i=0;i<cap;i++){
        cout<< arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main (){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    // cq.print();
    while(!cq.empty()){
        cout<<cq.front()<<" ";
        cq.pop();
    }
    cout<<endl;
    return 0;
}
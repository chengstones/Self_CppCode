#include <iostream>
using namespace std;

template <class elemType>
class queue{
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() const = 0;
    virtual ~queue(){}
};

template <class elemType>
class linkQueue:public queue<elemType>{
private:
    struct node{
        elemType data;
        node* next;
        node(const elemType &x, node* N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL){}
    };
    node *front, *rear;

public:
    linkQueue(){
        front = rear = NULL;
    }
    ~linkQueue(){
        node *delp;
        while(front){
            delp = front;
            front = front->next;
            delete delp;
        }
    }
    bool isEmpty() const{
        return front == NULL;
    }
    void enQueue(const elemType &x){
        if(rear == NULL) 
            front = rear = new node(x);
        else
            rear = rear -> next = new node(x);
    }
    elemType deQueue(){
        node* delp = front;
        elemType value = front -> data;
        front = front -> next;
        if(front == NULL) rear = NULL;
        delete delp;
        return value;
    }
    elemType getHead() const{
        return front -> data;
    }
};

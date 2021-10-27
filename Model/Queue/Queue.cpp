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
class seqQueue:public queue<elemType>{
private:
    elemType* elem;
    int maxSize;
    int front,rear;
    void doubleSpace(){
        elemType* tmp = elem;
        elem = new elemType[maxSize*2];
        for(int i(1);i<maxSize;++i){
            elem[i] = tmp[(front+i)%maxSize];
        }
        front = 0; rear = maxSize - 1;
        maxSize *= 2;
        delete []tmp;
    }

public:
    seqQueue(int initSize = 10){
        maxSize = initSize;
        front = rear = 0;
        elem = new elemType[maxSize];
    }
    ~seqQueue(){delete []elem;}
    bool isEmpty() const{
        return front == rear;
    }
    void enQueue(const elemType &x){
        if(front == (rear+1)%maxSize) doubleSpace();
        rear = (rear + 1) % maxSize;
        elem[rear] = x;
    }
    elemType deQueue(){
        front = (front + 1) % maxSize;
        return elem[front];
    }
    elemType getHead() const{
        return elem[(front+1) % maxSize];
    }
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

// int main(){
//     seqQueue<int> q1(2);
//     for(int i(0);i<10;++i){
//         q1.enQueue(i);
//     }
//     cout << q1.getHead() << ' ' << q1.isEmpty() << ' ';
//     cout << endl;
//     for(int i(0);i<10;++i){
//         cout << q1.deQueue() << ' ';
//     }
//     cout << endl;
//     return 0;
// }

// int main(){
//     linkQueue<int> q1;
//     for(int i(0);i<10;++i){
//         q1.enQueue(i);
//     }
//     cout << q1.getHead() << ' ' << q1.isEmpty() << ' ';
//     cout << endl;
//     for(int i(0);i<10;++i){
//         cout << q1.deQueue() << ' ';
//     }
//     cout << endl;
//     return 0;
// }
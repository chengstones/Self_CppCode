#include <iostream>
using namespace std;

class linkQueue{
private:
    struct node{
        int data;
        node* next;
        node(int x, node* N = NULL){
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
    void enQueue(int x){
        if(rear == NULL) 
            front = rear = new node(x);
        else
            rear = rear -> next = new node(x);
    }
    int deQueue(){
        node* delp = front;
        int value = front -> data;
        front = front -> next;
        if(front == NULL) rear = NULL;
        delete delp;
        return value;
    }
    int getHead() const{
        return front -> data;
    }
};

bool gcd(int p, int q){
    return q % p != 0;
}

int main(){
    int N,K;
    cin >> N >> K;

    linkQueue<int> * array = new linkQueue[N+1];
    for(int i(2);i<=N;++i){
        for(int j(i-1);j>0;--j){
            if(gcd(j,i)) array[i].enQueue(j);
        }
    }

    for(int i(0);i<K;++i){
        
    }


    return 0;
}
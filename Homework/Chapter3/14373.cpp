#include <iostream>

using namespace std;

class Queue{

private:
    int MaxSize;
    int front, rear;
    int* elem;

    void doublespace(){
        int* tmp = elem;
        elem = new int[MaxSize*2];
        for(int i(1);i<MaxSize;++i){
            elem[i] = tmp[(front+i)%MaxSize];
        }
        front = 0;rear = MaxSize-1;
        MaxSize *= 2;
        delete []tmp;
    }

public:
    Queue(int initlen = 10){
        MaxSize = initlen;
        front = rear = 0;
        elem = new int[MaxSize];
    }
    ~Queue(){delete []elem;}

    void enQueue(int data){
        if ((front == (1 + rear)%MaxSize)||MaxSize == 1) doublespace();
        rear = (rear+1)%MaxSize;
        elem[rear] = data;
        cout << rear << ' ' << (rear + MaxSize - front)%MaxSize<< endl;
    }

    void deQueue(){
        if (front == rear) cout << front << ' '<< 0 << endl;
        else{
            front = (front+1)%MaxSize;
            cout << front << ' ' << (rear + MaxSize - front)%MaxSize<< endl;
        }
    }
};

int main(){
    int s,n;
    int opt,data;
    cin >> s >> n;
    Queue* q = new Queue(s);
    for(int i(0);i<n;++i){
        cin >> opt;
        switch (opt){
            case 0: cin >> data;q->enQueue(data);break;
            case 1: q->deQueue();break;
        }
    }
    return 0;
}

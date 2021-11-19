#include <iostream>
#include <time.h>
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


template <class Type>
class priorityQueue{
private:
    int currentSize;
    Type *array;
    int maxSize;

    void doubleSpace(){
        Type* delp(array);
        maxSize *= 2;
        array = new Type[maxSize];
        for(int i(1);i<=currentSize;++i){
            array[i] = delp[i];
        }
        delete []delp;
    }
    
    void percolateDown(int hole){
        int child;
        Type tmp = array[hole];

        for(;hole*2 <= currentSize; hole = child){
            child = hole * 2;
            if(child != currentSize && array[child+1] < array[child]){
                ++child;
            }
            if(array[child] < tmp) array[hole] = array[child];
            else break;
        }
        array[hole] = tmp;
    }

    void buildHeap(){
        for(int i(currentSize/2);i>0;--i){
            percolateDown(i);
        }
    }

public:
    priorityQueue(int capacity = 100){
        array = new Type[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    
    priorityQueue(const Type items[], int size):maxSize(size+10),currentSize(size){
        array = new Type[maxSize];
        for(int i(0);i<size;++i){
            array[i+1] = items[i];
        }
        buildHeap();
    }
    
    ~priorityQueue(){
        delete []array;
    }
    
    bool isEmpty() const{
        return currentSize == 0;
    }

    void enQueue(const Type &x){
        if(currentSize == maxSize - 1) doubleSpace();

        int hole = ++currentSize;
        for(;hole>1 && x < array[hole/2];hole/=2){
            array[hole] = array[hole/2];
        }
        array[hole] = x; // hole == 1  or  x >= array[hole/2]
    }

    Type deQueue(){
        Type minItem;
        minItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return minItem;
    }

    Type getHead() const{
        return array[1];
    }
};

class simulator{
    int noOfServer;
    int arrivalLow;
    int arrivalHigh;
    int serviceTimeLow;
    int serviceTimeHigh;
    int customNum;

    struct eventT{
        int time;
        int type;
        bool operator< (const eventT &e)const {return time < e.time;}
    };

    public:
        simulator();
        int avgWaitTime();
};

simulator::simulator(){
    //cout << "请输入柜台数:"; 
    cin >> noOfServer;
    //cout << "请输入到达时间间隔的上下界（最小间隔时间   最大间隔时间）:";
    cin >> arrivalLow >> arrivalHigh;
    //cout << "请输入服务时间的上下界（服务时间下界   服务时间上界）：";
    cin >> serviceTimeLow >> serviceTimeHigh;
    //cout << "请输入模拟顾客数："; 
    cin >> customNum;

    srand(time(NULL));
}

int simulator::avgWaitTime(){
    int serverBusy = 0;
    int currentTime;
    int totalWaitTime = 0;
    linkQueue<eventT> waitQueue;
    priorityQueue<eventT> eventQueue;

    eventT currentEvent;

    int i;
    currentEvent.time = 0;
    currentEvent.type = 0;
    for(i = 0;i<customNum;++i){
        currentEvent.time += arrivalLow + (arrivalHigh - arrivalLow + 1)*rand()/(RAND_MAX + 1);
        eventQueue.enQueue(currentEvent);
    }

    while(!eventQueue.isEmpty()){
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch(currentEvent.type){
            case 0:{
                if(serverBusy != noOfServer){
                    ++serverBusy;
                    currentEvent.time += serviceTimeLow + (serviceTimeHigh - serviceTimeLow + 1) * rand() / (RAND_MAX + 1);
                    currentEvent.type = 1;
                    eventQueue.enQueue(currentEvent);
                }
                else waitQueue.enQueue(currentEvent);
            }
            break;
            case 1:{
                if(!waitQueue.isEmpty()){
                    currentEvent = waitQueue.deQueue();
                    totalWaitTime += currentTime - currentEvent.time;
                    currentEvent.time = currentTime + serviceTimeLow+(serviceTimeHigh - serviceTimeLow + 1)*rand()/(RAND_MAX + 1);
                    currentEvent.type = 1;
                    eventQueue.enQueue(currentEvent);
                }
                else --serverBusy;
            }
        }
    }
    return totalWaitTime / customNum;
}
int main()
{
    simulator sim;
    cout << sim.avgWaitTime() << endl;
    //<< "平均等待时间："
    return 0;
}

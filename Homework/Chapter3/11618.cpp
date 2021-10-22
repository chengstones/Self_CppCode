#include <iostream>

using namespace std;

template <class elemType>
class seqQueue{
private:
    elemType* elem;
    int maxSize;
    int front,rear;
    void doubleSpace(){
        elemType* tmp = elem;
        elem = new elemType[2*maxSize];
        for (int i(1);i<maxSize;++i){
            elem[i] = tmp[(front+i)%maxSize];
        }
        front = 0; rear = maxSize-1;
        maxSize *= 2; delete []tmp;
    }

public:
    seqQueue(int initSize = 10){
        maxSize = initSize;
        elem = new elemType[maxSize];
        front = rear = 0;
    }
    ~seqQueue(){delete []elem;}
    bool isEmpty() const{
        return front == rear;
    }
    void enQueue(const elemType &x){
        if((rear+1)%maxSize == front) doubleSpace();
        rear = (rear+1)%maxSize;
        elem[rear] = x;
    }
    elemType deQueueL(){
        front = (front + 1)%maxSize;
        return elem[front];
    }
    elemType deQueueR(){
        rear = (rear + maxSize - 1)%maxSize;
        return elem[rear];
    }
    elemType getHead() const{
        return elem[(front+1)%maxSize];
    }
    elemType getRear() const{
        return elem[rear];
    }
};


int main(){
    int N,K;cin >> N >> K;
    
    int* bigarray = new int[N-K+1];
    int* array = new int[N];
    seqQueue<int> small, big;

    int x;
    cin >> x;
    small.enQueue(x);
    big.enQueue(x);
    array[0] = x;

    for(int i(1);i<K;++i){
        cin >> x;
        array[i] = x;
        
        if(small.isEmpty()) small.enQueue(x);
        else if(x>small.getRear()) small.enQueue(x);
        else if(x<=small.getRear()){
                while(not small.isEmpty() && x<small.getRear()){
                    small.deQueueR();
                }
                small.enQueue(x);
            }
        
        if(big.isEmpty()) big.enQueue(x);
        else if(x<big.getRear()) big.enQueue(x);
        else if(x>=big.getRear()){
                while(not big.isEmpty() && x>big.getRear()){
                    big.deQueueR();
                }
                big.enQueue(x);
            }
        }
    
    for(int i(K);i<N;++i){
        cout << small.getHead() << ' ';
        bigarray[i-K] = big.getHead();
        cin >> x;
        array[i] = x;
        if(array[i-K] == small.getHead()) small.deQueueL();
        if(array[i-K] == big.getHead()) big.deQueueL();

        if(small.isEmpty()) small.enQueue(x);
        else if(x>small.getRear()) small.enQueue(x);
        else if(x<=small.getRear()){
                while(not small.isEmpty() && x<small.getRear()){
                    small.deQueueR();
                }
                small.enQueue(x);
            }
        
        if(big.isEmpty()) big.enQueue(x);
        else if(x<big.getRear()) big.enQueue(x);
        else if(x>=big.getRear()){
                while(not big.isEmpty() && x>big.getRear()){
                    big.deQueueR();
                }
                big.enQueue(x);
            }
        }


    cout << small.getHead() << ' ' << endl;
    bigarray[N-K] = big.getHead();
    
    for(int i(0);i<N-K+1;++i){
        cout << bigarray[i] << ' ';
    }

    delete [] bigarray;
    delete [] array;
}

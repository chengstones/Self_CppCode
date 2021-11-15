#include <iostream>
using namespace std;

class Node{
public:
    long long int p,q;
    Node(long long int p0, long long int q0):p(p0),q(q0){}
};

bool operator>(const Node& obj1,const Node& obj2){
    if(obj1.p * obj2.q > obj1.q * obj2.p) return true;
    return false;
} 

bool isFrac(long long int p, long long int q){
    // p < q
    while(p!=0){
        if(p == 1) return true;
        q = q % p;
        p ^= q ^= p ^= q;
    }
    return false;
}

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
            if(child != currentSize && *array[child+1] > *array[child]){
                ++child;
            }
            if(*array[child] > *tmp) array[hole] = array[child];
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
    priorityQueue(int capacity = 10){
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
        for(int i(1);i<=maxSize;++i) delete array[i];
        delete []array;
    }
    
    bool isEmpty() const{
        return currentSize == 0;
    }

    void enQueue(const Type &x){
        if(currentSize == maxSize - 1) doubleSpace();

        int hole = ++currentSize;
        for(;hole>1 && *x > *array[hole/2];hole/=2){
            array[hole] = array[hole/2];
        }
        array[hole] = x;
    }

    Type deQueue(){
        Type maxItem;
        maxItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return maxItem;
    }

    Type getHead() const{
        return array[1];
    }
};



int main(){
    int N, K; 
    cin >> N >> K;

    priorityQueue<Node*>* array = new priorityQueue<Node*>;

    Node* p;
    for(int i(2);i<=N;++i){
        p = new Node(i-1,i);
        array->enQueue(p);
    }

    long long int a,b;
    for(int i(1);i<K;++i){
        p = array->deQueue();
        if (p->p == 1) continue;
        a = p->p - 1; b = p->q;
        while(!isFrac(a,b)){
            --a; 
        }
        p = new Node(a,b);
        array->enQueue(p);
    }

    p = array->getHead();
    cout << p -> p << '/' << p -> q;
}
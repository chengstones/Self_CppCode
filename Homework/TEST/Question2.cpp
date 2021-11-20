#include <iostream>
using namespace std;


struct Patient{
    int ID;
    int Priority;
    Patient(int ID_ = 0, int Priority_ = 0):ID(ID_),Priority(300000 - Priority_ * 2000 + ID){}
};


class priorityQueue{
private:
    int currentSize;
    Patient *array;
    int maxSize;
    
    void percolateDown(int hole){
        int child;
        Patient tmp = array[hole];

        for(;hole*2 <= currentSize; hole = child){
            child = hole * 2;
            if(child != currentSize && array[child+1].Priority < array[child].Priority){
                ++child;
            }
            if(array[child].Priority < tmp.Priority) array[hole] = array[child];
            else break;
        }
        array[hole] = tmp;
    }

public:
    priorityQueue(int capacity = 2000){
        array = new Patient[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    
    ~priorityQueue(){
        delete []array;
    }
    
    bool isEmpty() const{
        return currentSize == 0;
    }

    void enQueue(const Patient &x){

        int hole = ++currentSize;
        for(;hole>1 && x.Priority < array[hole/2].Priority;hole/=2){
            array[hole] = array[hole/2];
        }
        array[hole] = x; // hole == 1  or  x >= array[hole/2]
    }

    Patient deQueue(){
        Patient minItem;
        minItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return minItem;
    }

    Patient getHead() const{
        return array[1];
    }
};

int main()
{
    int N; cin >> N;
    char* INSTRUCT = new char[4];

    priorityQueue* array = new priorityQueue[3];

    int X,Y;
    int ID(1);
    for(int i(0);i<N;++i){
        cin >> INSTRUCT;
        switch(INSTRUCT[0]){
            case 'I':{
                cin >> X >> Y;
                array[X-1].enQueue(Patient(ID,Y));
                ++ID; 
            } break;
            case 'O':{
                cin >> X;
                if(array[X-1].isEmpty()) cout << "EMPTY";
                else {cout << array[X-1].getHead().ID;
                array[X-1].deQueue();}
                cout << endl;
            } break;
        }
    }
    delete []array;
    delete []INSTRUCT;
    return 0;
}

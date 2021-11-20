#include <iostream>
#include <cstring>
using namespace std;
class shenfen{
public:
    int id;
    int priority;
    shenfen(int i,int p){
        id=i;priority=p;
    }
    shenfen(){
        id=0;priority=0;
    }
    bool operator >(const shenfen &x)const{
        if (priority>x.priority)return true;
        else if (priority==x.priority){
            if (id<x.id){
                return true;
            }else return false;
        }else return false;
    }
    bool operator ==(const shenfen&x)const{
        return id==x.id&&priority==x.priority;
    }
    bool operator <(const shenfen&x)const{
        if (priority<x.priority)return true;
        else if (priority==x.priority){
            if (id>x.id){
                return true;
            }else return false;
        }else return false;
    }
};
template <class T>
class priorityqueue
{

private:
    int currentsize;
    int maxsize;
    T * a;
    void doublespace()
    {
        T * tmp = a;
        a = new T[maxsize*2];
        for (int i =1;i<=currentsize;i++)
        {
            a[i] = tmp[i];
        }
        delete [] tmp;
        maxsize*=2;
    }
    void buildheap( )
    {
        for (int i = currentsize/2;i>0;i--)
        {
            percolatedown(i);
        }
    }
    void percolatedown( int hole )
    {
        T tmp = a[hole];
        int child;
        for (hole;hole*2<=currentsize;hole= child)
        {
            child = hole*2;
            if ((child!=currentsize)&&(a[child+1]>a[child]))
            {
                child+=1;
            }
            if (a[child]>tmp)
            {
                a[hole] = a[child];
            }
            else
            {
                break;
            }
        }
        a[hole] = tmp;
    }


public:
    priorityqueue( int capacity = 100 )
    { a = new T[capacity];
        maxsize = capacity;
        currentsize = 0;
    }
    priorityqueue( const T data[], int size )
    {
        maxsize = size+10;
        currentsize = size;
        a = new T[maxsize];
        for (int i =0;i<size;i++)
        {
            a[i+1] = data[i];
        }
        buildheap();
    }
    ~priorityqueue()
    { delete [] a; }
    bool isempty( ) const
    { return currentsize == 0; }
    T getHead() { return a[1]; }
    void enqueue( const T & x )
    {
        if (currentsize==maxsize-1)
        {
            doublespace();
        }
        currentsize+=1;
        int hole = currentsize;
        for (hole;hole>1&&x>a[hole/2];hole/=2)
        {
            a[hole] =a[hole/2];
        }
        a[hole] = x;
    }
    T dequeue()
    {
        T max = a[1];
        a[1] = a[currentsize];
        currentsize-=1;
        percolatedown(1);
        return max;
    }
    int length()
    {
        return currentsize;
    }
};

int main(){
    int n;
    cin>>n;
    long long id=1;
    priorityqueue<shenfen> q1;
    priorityqueue<shenfen> q2;
    priorityqueue<shenfen> q3;
    int docotor;
    int pri;
    for(int i=0;i<n;i++){
        char* record=new char[3];
        cin>>record;
        if(record[0]=='I'){

            cin>>docotor;
            cin>>pri;
            shenfen s(id,pri);
            if(docotor==1){
                q1.enqueue(s);
            }else if(docotor==2){
                q2.enqueue(s);
            }else if(docotor==3){
                q3.enqueue(s);
            }
            id++;
        }
        else if(record[0]=='O'){
            shenfen s;
            cin>>docotor;
           if(docotor==1) {
               if (!q1.isempty()) {
                   s = q1.dequeue();
                   cout << s.id << endl;
               }
               else {cout << "EMPTY" << endl; }

           }
           else if(docotor==2){
               if (!q2.isempty()) {
                   s = q2.dequeue();
                   cout << s.id << endl;
               } else { cout << "EMPTY" << endl; }

           }else{
               if (!q3.isempty()) {
                   s = q3.dequeue();
                   cout << s.id << endl;
               } else { cout << "EMPTY" << endl; }
           }

        }
    }
    return 0;
}
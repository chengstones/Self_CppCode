#include <iostream>
using namespace std;

template <class elemType>
class stack{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual ~stack(){}
};

template <class elemType>
class seqStack:public stack<elemType>{
private:
    elemType* elem;
    int currentLength;
    int maxSize;
    void doubleSpace(){
        elemType* tmp = elem;
        maxSize *= 2;
        elem = new elemType[maxSize];
        for(int i(0);i<currentLength;++i){
            elem[i] = tmp[i];
        }
        delete []tmp;
    }

public:
    seqStack(int initSize = 10){
        maxSize = initSize;
        currentLength = 0;
        elem = new elemType[maxSize];
    }
    ~seqStack(){delete []elem;}
    bool isEmpty() const{return currentLength == 0;}
    void push(const elemType &x){
        if (currentLength == maxSize) doubleSpace();
        ++currentLength;
        elem[currentLength - 1] = x;
    }
    elemType pop(){
        --currentLength;
        return elem[currentLength];
    }
    elemType top() const{
        return elem[currentLength - 1];
    }
};

template <class elemType>
class linkStack:public stack<elemType>{
private:
    struct node{
        elemType data;
        node* next;
        node(const elemType &x,node* n = NULL){
            data = x;
            next = n;
        }
        node():next(NULL){}
        ~node(){}
    };
    node* top_p;

public:
    linkStack(){top_p = NULL;}
    ~linkStack(){
        node* delp;
        while(top_p){
            delp = top_p;
            top_p = top_p ->next;
            delete delp;
        }
    }
    bool isEmpty() const{
        return top_p == NULL;
    }
    void push(const elemType &x){
        node* n = new node(x,top_p);
        top_p = n;
    }
    elemType pop(){
        bool flag(top_p == NULL);
        node* delp = top_p;
        top_p = top_p -> next;
        elemType ans(delp -> data);
        delete delp;
        return ans;
    }
    elemType top() const{
        return top_p -> data;
    }
};

int main(){
   seqStack<int> stack1(2);
   for(int i(0);i<10;++i){
       stack1.push(i);
       cout << stack1.top() << ' ' ;
   }
   for (int i(0);i<10;++i){
       cout << stack1.pop() << ' ';
   }
   return 0;
}

// int main(){
//     linkStack<int> stack1;
//         for(int i(0);i<2;++i){
//         stack1.push(i);
//         cout << stack1.top() << ' ' ;
//     }
//     for (int i(0);i<2;++i){
//         cout << stack1.pop() << ' ';
//     }

//     return 1;
// }

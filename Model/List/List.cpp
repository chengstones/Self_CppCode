#include <iostream>
using namespace std;

template <class elemType>
class list{
public:
    virtual void clear() = 0;
    virtual int length() const = 0;                    
    virtual void insert(int i, const elemType &x) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const elemType &x) const = 0;
    virtual elemType visit(int i) const = 0;
    virtual void traverse() const = 0;
    virtual ~list(){}
};

// 线性表的顺序实现
template <class elemType>
class seqList:public list<elemType>{
private:
    elemType* data;
    int currentLength;
    int maxsize;
    void doubleSpace(){
        elemType* tmp = data;
        maxsize *= 2;
        data = new elemType[maxsize];
        for(int i(0);i<currentLength;++i){
            data[i] = tmp[i];
        }
        delete []tmp;
    }

public:
    seqList(int initSize = 10){
        maxsize = initSize; 
        currentLength = 0;
        data = new elemType[maxsize];
    }
    ~seqList(){delete []data;}
    void clear(){currentLength = 0;}
    int length() const {return currentLength;}
    void insert(int i, const elemType &x){
        if(currentLength == maxsize) 
            doubleSpace();
        for(int j(currentLength);j>i;--j){
            data[j] = data[j-1];
        }
        data[i] = x;
        ++currentLength;
    }
    void remove(int i){
        for(int j(i);j<currentLength-1;++j){
            data[j] = data[j+1];
        }
        --currentLength;
    }
    int search(const elemType &x) const{
        for(int i(0);i<currentLength;++i){
            if (data[i] == x) return i;
        }
        return -1;
    }
    elemType visit(int i) const{
        return data[i];
    }
    void traverse() const{
        for(int i(0);i<currentLength;++i){
            cout << data[i] << ' ';
        }
        cout << endl;
    }
};

// 顺序表的链表实现
template <class elemType>
class slinkList:public list<elemType>{
private:
    struct node{
        elemType data;
        node* next;
        node(const elemType &x,node* N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL){}
    };

    node* head;

public:
    slinkList(){
        head = new node();
    }
    ~slinkList(){
        clear();
        delete head;
    }
    void clear(){
        node* p(head->next),*delp;
        head -> next = NULL; // Attention！！
        while(p){
            delp = p;
            p = p->next;
            delete delp;
        }
    }
    int length() const{
        node*p(head);
        int i(0);
        while(p->next){
            ++i;
            p = p->next;
        }
        return i;
    }
    void insert(int i, const elemType &x){
        node* p(head);
        for(int j(0);j<i;++j) p = p->next;
        node* tmp = new node(x,p->next);
        p -> next = tmp;
    }
    void remove(int i){
        node* p(head);
        for(int j(0);j<i;++j) p = p->next;
        node* delp(p->next);
        p->next = delp->next;
        delete delp;
    }
    int search(const elemType &x) const{
        node* p(head->next);
        int i(0);
        while(p){
            if (p->data == x){
                return i;
            }
            else{
                ++i;
                p = p->next;
            }
        }
        return -1;
    }
    elemType visit(int i) const{
        node* p(head->next);
        for(int j(0);j<i;++j) p = p->next;
        return p->data;
    }
    void traverse() const{
        node* p(head->next);
        while(p){
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }
};

template <class elemType>
class dlinkList:public list<elemType>{
private:
    struct node{
        elemType data;
        node* prev;
        node* next;
    
        node(const elemType &x,node* P = NULL,node* N = NULL){
            data = x;
            prev = P;
            next = N;
        }
        node():prev(NULL),next(NULL){}
    };
    node* head, *tail;
    dlinkList(){
        head = new node;
        head -> next = tail = new node;
        tail -> prev = head;
    }
    ~dlinkList(){
        clear();
        delete head;
        delete tail;
    }
    void clear(){
        node* p(head->next);
        node* delp;
        head->next = tail;
        tail->prev = next;
        while(p!=tail){
            delp = p;
            p = p->next;
            delete delp;
        }
    }
    int length() const{
        node* p(head->next);
        int i(0);
        while(p!=tail){
            ++i;
            p = p->next;
        }
        return i;
    }
    void insert(int i,const elemType &x){
        node* p(head);
        for(int j(0);j<i;++j) p = p->next;
        node* tmp = new node(x,p,p-->next);
        p -> next = tmp;
        tmp -> next -> prev = tmp;
    }
    void remove(int i){
        node *p(head);
        for (int j(0);j<i;++j) p = p->next;
        node* delp(p->next);
        p -> next = delp -> next;
        delp -> next -> prev = p;
        delete delp;
    }
    int search(const elemType &x) const{
        node *p(head -> next);
        int i(0);
        while(p!=tail){
            if (p->data == x) return i;
            p = p->next;
            ++i;
        }
        return -1;
    }
    elemType visit(int i) const{
        node *p(head -> next);
        for(int j(0);j<i;++j) p = p->next;
        return p->data;
    }
    void traverse() const{
        node*p (head -> next);
        while (p!= tail){
            cout << p->data << ' ';
        }
        cout << endl;
    }
};

//int main(){
//    seqList<int> array1(10);
//    for(int i(0);i<10;++i){
//        array1.insert(i,i);
//    }
//    array1.traverse();
//    array1.remove(1);
//    array1.traverse();
//    cout << array1.search(5)<< endl;
//    cout << array1.visit(4)<< endl;
//}

int main(){
    slinkList<int> array1;
    for(int i(0);i<10;++i){
        array1.insert(i,i);
    }
    array1.traverse();
    array1.remove(1);
    array1.traverse();
    cout << array1.search(5)<< endl;
    cout << array1.visit(4)<< endl;
}

// 简单链表
/*
给定一个N个数的数组，M次操作，每次操作为下列操作之一。求最后的数组。

操作1：在第X个数之后插入一个数Y。

操作2：删除第X个数。

第一行两个整数N，M（N，M≤100000）含义见试题描述。

第二行N个整数，表示原来的数组。

接下来M行，每行第一个数OPT，表示操作类型。

对于操作1，接下来两个数X，Y，含义见题面描述，保证0≤X≤当前数的个数，若X=0，表示在数组开头插入。

对于操作2，接下来一个数X，含义见题面描述，保证1≤X≤当前数的个数。
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int D = 0, Node* N = NULL):data(D),next(N){}
};


void _insert(Node* elem,int i, int x){
    Node* pos(elem);
    for(int j(0);j<i;++j) pos = pos->next;
    pos->next = new Node(x,pos->next);
}
    
void _remove(Node* elem, int i){
    Node* pos(elem);
    Node* delp;
    for(int j(0);j<i;++j) pos = pos->next;
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
}
    

int main(){
    int N,M;
    cin >> N >> M;
    Node* elem = new Node, *p(elem);
    int x;
    for(int i(0);i<N;++i){
        cin >> x;
        p = p -> next = new Node(x,NULL);
    }
    int opt,pos;
    for(int i(0);i<M;++i){
        cin >> opt;
        if (opt == 1){
            cin >> pos >> x;
            _insert(elem,pos,x);
        }
        else{
            cin >> pos;
            _remove(elem,pos-1);
        }
    }
    
    p = elem->next;
    while(p){
        cout << p->data << ' ';
        p = p->next;
    }
    return 0;
}
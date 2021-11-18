#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x = 0, Node* N = NULL):next(N),data(x){}
};

int main()
{
    int n,x; cin >> n; 
    Node* head = new Node, *p(head);
    for(int i(0);i<n;++i){
        cin >> x;
        p -> next = new Node(x, p->next);
        p = p -> next;
    }

    int compareNum(0);
    int m; cin >> m;
    Node *tmp;
    for(int i(0);i<m;++i){
        p = head;
        cin >> x;
        while(p->next!=NULL){
            ++compareNum;
            if(p->next->data == x){
                tmp = p->next;
                p->next = tmp->next;
                tmp -> next = head -> next;
                head -> next = tmp;
                break;
            }
            p = p -> next;
        }
    }
    
    cout << compareNum;
    
    p = head;
    Node* delp;
    while(p!=NULL){
        delp = p;
        p = p->next;
        delete delp;
    }
    return 0;
}

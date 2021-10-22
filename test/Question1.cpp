#include <iostream>
using namespace std;

struct node{
   int data;
   node* next;
   node* prev;
   node(int x,node* P = NULL,node* N = NULL){
      data = x;
      next = N;
      prev = P;
      }
   node():next(NULL),prev(NULL){}
   };

int main()
{
    node* head1 = new node(0);
    node* head2 = new node(0);
    int m,n;
    cin >> m >> n;
    node* p(head1), *q(head2);
    int x;
    for(int i(0);i<m;++i){
        cin >> x;
        p = p->next = new node(x,p);
    }
    for(int i(0);i<n;++i){
        cin >> x;
        q = q->next = new node(x,q);
    }
    int s(0);
    node* ans = new node(0),*v(ans);
    while(p!=head1&&q!=head2){
        s = p->data + q->data + s;
        v = v->next = new node(s%10,v);
        s /= 10;
        p = p->prev; q = q->prev;
    }
    node* tmp;
    if(p==head1) tmp = q; else tmp = p;
    while(tmp->prev!= NULL){
        s = tmp->data + s;
        v = v->next = new node(s%10,v);
        s /= 10;
        tmp = tmp->prev;
    }
    if(s==1) v = v->next = new node(1,v);
    while(v->prev!=NULL){
        cout << v->data << ' ';
        v = v->prev;
    }

    node* delp;
    while(head1!= NULL){
        delp = head1;
        head1 = head1 -> next;
        delete delp;
    }
    while(head2!= NULL){
        delp = head2;
        head2 = head2 -> next;
        delete delp;
    }
    while(ans!= NULL){
        delp = ans;
        ans = ans -> next;
        delete delp;
    }
}

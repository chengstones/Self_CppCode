#include <iostream>
using namespace std;

struct node{
   int data;
   node* next;
   node(int x,node* N = NULL){
      data = x;
      next = N;
      }
   node():next(NULL){}
   };

int main()
{
   int M,N;
   cin >> M;
   node* head = new node(0);
   int x;
   node* p(head);
   for(int i(0);i<M;++i){
      cin >> x;
      p = p->next = new node(x);
   }
   cin >> N;
   p = head;
   for(int i(0);i<N;++i){
      cin >> x;
      if(p->next == NULL && x<=p->next->data){
         p->next = new node(x,p->next);
      }
      else{
         while(p->next != NULL && x>p->next->data){
            p = p->next;
         }
         p->next = new node(x,p->next);
      }
   }
   p = head;
   node* delp;
   while(p->next!= NULL){
      delp = p;
      cout << p->next->data << ' ';
      p = p->next;
      delete delp;
   }
   delete p;
}

#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include "linklist.h"
using namespace std;

struct Type
{
    int coef; 
    int exp; 
};

template <class elemType>
struct Node
{
    elemType data;
    Node* next;
};

template <class elemType>
struct Polynomial
{
    private:
        Node<elemType>* head;
        elemType stop_flag; 
    public:
        ʽ
        Polynomial(const elemType &stop);
        void getPoly(); 
        void addPoly(const Polynomial &L1, const Polynomial &L2); 
        void dispPloy();ʽ
        void clear();
        ~Polynomial(){clear(); delete head;};
};


template <class elemType>
void getStop(elemType &stopFlag)־
{
    int c,e;

    cin>>c>>e;
    stopFlag.coef = c;
    stopFlag.exp = e;
}

template <class elemType>
Polynomial<elemType>::Polynomial(const elemType &stop)ʽ
{
    head = new Node<elemType>();
    stop_flag.coef = stop.coef;
    stop_flag.exp = stop.exp;
}

template <class elemType>
void Polynomial<elemType>::getPoly() ʽ
{
    Node<elemType> *p, *tmp;
    elemType e;

    p=head;

    cin>>e.coef>>e.exp;

    while (true)
    {
        if ((e.coef==stop_flag.coef)&&(e.exp==stop_flag.exp)) break;

        tmp = new Node<elemType>();
        tmp->data.coef = e.coef;
        tmp->data.exp = e.exp;
        tmp->next = NULL;
        p->next = tmp;
        p=tmp;

        cin>>e.coef>>e.exp;
    }
}

template <class elemType>
void Polynomial<elemType>::addPoly(const Polynomial &La,
                                   const Polynomial &Lb)
{
    Node<elemType> *pa, *pb, *pc;
    Node<elemType> *tmp;

    pa = La.head->next; 㣩
    pb = Lb.head->next; 㣩
    pc = head; 

    while (pa&&pb) 
    {
        if (pa->data.exp==pb->data.exp)
        {
            if (pa->data.coef+pb->data.coef == 0) {pa=pa->next; pb=pb->next; continue;}
            else
            {
                tmp = new Node<elemType>();
                tmp->data.coef = pa->data.coef + pb->data.coef;
                tmp->data.exp = pa->data.exp;
                tmp->next = NULL;
                pa=pa->next; pb=pb->next;
            }
        }
        else if (pa->data.exp>pb->data.exp)
            {
                tmp = new Node<elemType>();
                tmp->data.coef = pb->data.coef;
                tmp->data.exp = pb->data.exp;
                tmp->next = NULL;
                pb=pb->next;
            }
            else
            {
                tmp = new Node<elemType>();
                tmp->data.coef = pa->data.coef;
                tmp->data.exp = pa->data.exp;
                tmp->next = NULL;
                pa=pa->next;
            }


        pc->next = tmp;
        pc=tmp;
    }

    ȥ
    while (pa) 
    {
        tmp = new Node<elemType>();
        tmp->data.coef = pa->data.coef;
        tmp->data.exp = pa->data.exp;
        tmp->next = NULL;

        pa=pa->next;
        pc->next = tmp;
        pc=tmp;

    }
    while (pb) 
    {
        tmp = new Node<elemType>();
        tmp->data.coef = pb->data.coef;
        tmp->data.exp = pb->data.exp;
        tmp->next = NULL;

        pb=pb->next;
        pc->next = tmp;
        pc=tmp;
    }
}

template <class elemType>
void Polynomial<elemType>::dispPloy()ʽ
{
    Node<elemType> *p;
    p=head->next;




    while (p)
    {
        cout<<p->data.coef<<"  "<<p->data.exp<<"\n";
        p=p->next;
    }
    cout<<endl;
}

template <class elemType>
void Polynomial<elemType>::clear()ʽ
{
    Node<elemType> *p, *q;
    p=head->next; 

    while (p) 
    {
        q=p->next;
        delete p;
        p=q;
    }
}

#endif // POLYNOMIAL_H_INCLUDED

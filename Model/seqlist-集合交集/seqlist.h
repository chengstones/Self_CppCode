#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
#include <iostream>
#define INITSIZE 100
using namespace std;

class illegalSize{};
class outOfBound{};

template <class elemType>
class seqList
{    private:
        elemType *elem; 
	    int len;        
    	int maxSize;
    	void doubleSpace();
    public:
        seqList(int size=INITSIZE); 
        bool isEmpty()const { return ( len == 0 ); }
        bool isFull()const { return (len == maxSize); }
        int length()const {return len;}  
        elemType get(int i )const;
        int find (const elemType &e )const;

        void insert(int i, const elemType &e );
        void remove(int i, elemType &e );

        void clear() { len=0; }; 
        ~seqList() { delete []elem; };
};

template <class elemType>
seqList<elemType>::seqList(int size)
{
    elem = new elemType[size];
    if (!elem) throw illegalSize();
    maxSize = size-1;
    len = 0;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
    int i;
    elemType *tmp = new elemType[2*maxSize];
    if (!tmp) throw illegalSize();

    for (i=1; i<=len; i++)
        tmp[i] = elem[i];

    delete []elem;
    elem = tmp;
    maxSize = 2*maxSize - 1;
}

template <class elemType>
elemType seqList<elemType>::get(int i)const
{
    if ((i<1)||(i>len)) throw outOfBound();
    return elem[i];
}

template <class elemType>
int seqList<elemType>::find (const elemType &e )const
{
    int i;
    elem[0] = e; 
    for (i=len; i>=0; i--)
        if (elem[i]==e) break;
    return i;
}

template <class elemType>
void seqList<elemType>::insert (int i, const elemType &e )
{
    int k;
    if ((i<1)||(i>len+1)) return; 
    if (len==maxSize) doubleSpace();

    for (k=len+1; k>i; k--)
        elem[k]=elem[k-1];
    elem[i]=e;
    len++;
}

template <class elemType>
void seqList<elemType>::remove (int i, elemType &e )
{
    int k;
    if ((i<1)||(i>len)) return;
    e=elem[i];

    for (k=i; k<len; k++)
        elem[k]=elem[k+1];
    len--;
}

#endif // SEQLIST_H_INCLUDED

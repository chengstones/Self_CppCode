#include <iostream>
using namespace std;


void percolateDown(int a[],int hole, int size){
    int child;
    int tmp = a[hole];

    for(;hole*2+1<size;hole = child){
        child = hole * 2 + 1;
        if(child != size - 1&& a[child + 1]>a[child])
            child ++;
        if(a[child]>tmp) a[hole] = a[child];
        else break;
    }
    a[hole] = tmp;
}

void heapSort(int a[],int size){
    int i;
    int tmp;
    for(i = size/2 - 1; i>=0;--i)
        percolateDown(a,i,size);

    for(i = size - 1; i>0;--i){
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        percolateDown(a,0,i);
    }
}
int main()
{
    int a[] = {1,3,5,7,2,4,6};
    heapSort(a,7);
    for(int i(0);i<7;++i) cout <<  a[i];
    return 0;
}

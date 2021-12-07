#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right){
    int *tmp = new int[right-left+1];

    int i = left,j = mid,k = 0;

    while(i<mid&&j<=right){
        if(a[i]<a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }

    while(i<mid) tmp[k++] = a[i++];
    while(j<=right) tmp[k++] = a[j++];

    for(i = 0,k = left; k<=right;) a[k++] = tmp[i++];
    delete []tmp;
}

void mergeSort(int a[], int left, int right){
    int mid = (left + right) / 2;

    if(left == right) return;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid+1,right);
}

void mergeSort(int a[], int size){
    mergeSort(a,0,size-1);
}

int main()
{
    int a[] = {1,4,3,6,4,2,1};
    mergeSort(a,7);
    for(int i(0);i<7;++i) cout <<  a[i];
    return 0;
}

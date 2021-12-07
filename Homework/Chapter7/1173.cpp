#include <iostream>
using namespace std;

int divide(long long int a[], int low, int high){
    long long int k = a[low];
    do{
        while(low<high && a[high] >= k) --high;
        if(low < high) {a[low] = a[high];++low;}
        while(low<high && a[low] <= k) ++low;
        if(low < high) {a[high] = a[low];--high;}
    }while(low!=high);
    a[low] = k;
    return low;
}

void quickSort(long long int a[], int low,int high){
    int mid;
    if(low >= high) return;
    mid = divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}

void quickSort(long long int a[], int size){
    quickSort(a,0,size-1);
}

int main(){
    int n; cin >> n;
    long long int * array1_ = new long long int[n];
    long long int * array2_ = new long long int[n];
    for(int i(0);i<n;++i){cin >> array1_[i];}
    for(int i(0);i<n;++i){cin >> array2_[i];}

    quickSort(array1_,n);
    quickSort(array2_,n);
    long long  MaxS(0), MinS(0);
    for(int i(0);i<n;++i){
        MaxS += array1_[i] * array2_[i];
        MinS += array1_[i] * array2_[n - i - 1];
    }
    
    cout << MaxS << ' ' << MinS;
    delete []array1_;
    delete []array2_;
    
}
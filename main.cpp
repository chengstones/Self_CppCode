#include <iostream>
#include <algorithm>
using namespace std;
int n;
int target;
void merge(int a[],int left,int mid,int right){
    int* tmp=new int[right-left+1];
    int i=left,j=mid,k=0;
    while(i<mid && j<=right){
        if(a[i]<a[j]) tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
    }
    while(i<mid) tmp[k++]=a[i++];
    while(j<=right) tmp[k++]=a[j++];
    for(int i=0,k=left;k<=right;) a[k++]=tmp[i++];
    delete []tmp;
}
void mymerge(int* num,int begin,int end){
    if(target<=0) return;
    if(begin>=end) {target--;return;}
    int mid=(begin+end)/2;
    mymerge(num,begin,mid-1);
    mymerge(num,mid,end);
    merge(num,begin,mid,end);
    target--;
}
int main(){
    int k;
    scanf("%d%d",&n,&k);
    if(k%2==0 || k>2*n-1){
        cout<<-1;
        return 0;
    }
    target=2*n-1-k;
    int* num=new int[n];
    for(int i=0;i<n;i++){
        num[i]=n-i;
    }
    mymerge(num,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    delete []num;

}


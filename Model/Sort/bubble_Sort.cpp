#include <iostream>
using namespace std;

void bubbleSort(int a[],int size){
    int i,j;
    bool flag = true;
    int tmp;
    
    for(i = 1;i<size && flag;++i){
        flag = false;
        for(j=0;j<size-i;++j)
        if(a[j+1]<a[j]){
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            flag = true;
        }
    }
}

int main()
{
    
    system("pause");
    return 0;
}

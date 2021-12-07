#include <iostream>
using namespace std;

void simpleSelectSort(int a[],int size){
    int i,j,min;
    int tmp;
    for(i = 0;i<size-1;++i){
        min = i;
        for(j = i+1;j<size;++j)
            if(a[j]<a[min]) min = j;
        tmp = a[i];a[i]=a[min];a[min]=tmp;
    }
}

int main()
{
    
    system("pause");
    return 0;
}

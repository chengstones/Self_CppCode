#include <iostream>
using namespace std;

void shellSort(int array[], int size){
    int step,i,j;
    int tmp;

    for(step = size/2;step>0;step/=2)
        for(i = step;i<size;++i){
            tmp = array[i];
            for(j = i-step;j>=0 && array[j]>tmp;j-=step)
                array[j+step] = array[j];
            array[j+step] = tmp;
        }
}

int main()
{
    
    system("pause");
    return 0;
}

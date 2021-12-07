#include <iostream>
using namespace std;

void simpleInsertSort(int array[], int size){
    // small -> large
    int k;
    int tmp;

    for(int j(1);j<size;++j){
        tmp = array[j];
        for(k = j-1;k>=0 && tmp < array[k];--k)
            array[k+1] = array[k];
        array[k+1] = tmp;
    }

    return;
}

int main()
{
    
    system("pause");
    return 0;
}

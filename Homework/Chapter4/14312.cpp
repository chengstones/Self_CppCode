#include <iostream>
using namespace std;

int search(int array[], int start, int end, int x){
    int loc(start);
    for(;loc<=end;loc++){
        if(array[loc] == x) return loc;
    }
    return loc;
}

void Fun(int array1[], int start1, int end1, int array2[], int start2, int end2){
    int root = array1[start1];
    int loc = search(array2,start2,end2,root);
    int num1 = loc - start2;
    int num2 = end2 - loc;
    if(num1 == 0);
    else if(num1 == 1) cout << array2[loc-1] << ' ';
    else{
        end1 = start1 + num1;
        ++start1;
        end2 = loc - 1;
        start2 = loc - num1;
        Fun(array1,start1,end1,array2,start2,end2);
        --start1;
    } 
    if(num2 == 0);
    else if(num2 == 1) cout << array2[loc+1] << ' ';
    else{
        start1 = start1 + num1 + 1;
        end1 = start1 + num2 - 1;
        start2 = loc + 1;
        end2 = loc + num2;
        Fun(array1,start1,end1,array2,start2,end2);
    }
    cout << array2[loc] << ' ';
}

int main()
{
    int n,x; cin >> n;
    int *array1 = new int[n];
    int *array2 = new int[n];
    for(int i(0);i<n;++i){
        cin >> x;
        array1[i] = x;
    }
    for(int i(0);i<n;++i){
        cin >> x;
        array2[i] = x;
    }
    Fun(array1,0,n-1,array2,0,n-1);
    delete []array1;
    delete []array2;
    return 0;
}

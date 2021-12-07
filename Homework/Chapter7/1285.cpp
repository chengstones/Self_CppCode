#include <iostream>
using namespace std;

void my_rank(int *array, int low, int high, int k){
    if(k == 1) return ;
    if(high - low + 1== (k + 1)/2){
        for(int i(0);i<(high - low + 1)/2;++i)
            array[low+i] ^= array[high-i] ^= array[low+i] ^= array[high-i];
        return ;
    }
    int k0 = (k - 2) < (((high - low + 1)/2) * 2 - 1)? k - 2 : ((high - low + 1)/2) * 2 - 1;
    int flag1 = array[low],flag2 = array[high];
    for(int i(0);i<high - low + 1;++i) array[low+i] = (((high-low)/2+1) + i)% (flag2 - flag1 + 1) + flag1;
    my_rank(array,low,low + (high-low+1)/2-1,k0);
    my_rank(array,low+(high-low+1)/2,high,k - k0 - 1);
}

int main()
{
    int n,k;
    cin >> n >> k;
    if( k%2 == 0 || k > 2 * n || k < 1){
        cout << -1; 
        return 0;
    }

    int *array = new int[n];
    for(int i(0);i < n;++i) array[i] = i + 1;

    my_rank(array,0,n-1,k);
    for(int i(0);i<n;++i)
        cout << array[i] << ' ';
    delete []array;
    return 0;
}
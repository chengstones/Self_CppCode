#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    if( k%2 == 0 || k > 2 * n || k < 1){
        cout << -1; 
        return 0;
    }
    int Num = n - (k + 1)/2;
    int pre(Num/2),pos((Num+1)/2),mid(n - pre - pos);
    for(int i(0);i < pre;++i)
        cout << i + 1 << ' ';
    for(int i(0);i < mid;++i)
        cout << mid + pre - i << ' ';
    for(int i(0);i < pos;++i)
        cout << mid + pre + i + 1 << ' ';

    return 0;
}

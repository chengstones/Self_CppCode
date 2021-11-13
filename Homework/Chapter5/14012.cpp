#include <iostream>
using namespace std;

const long long int MAX_VALUE = 9223372036854775807;
struct node{
    long long int weight;
    int parent;
    node():parent(0){}
};

int main()
{
    int n;
    cin >> n;
    int size = 2 * n;
    node* array = new node[size];   
    
    for(int i(n);i<size;++i){
        cin >> array[i].weight; 
    }

    long long int min1, min2; 
    int l1, l2;
    for(int i(n-1);i>0;--i){
        min1 = min2 = MAX_VALUE;
        for(int j(i+1);j<size;++j){
            if (array[j].parent != 0) continue;
            if (array[j].weight <= min1){
                min2 = min1;
                min1 = array[j].weight;
                l2 = l1;
                l1 = j;
            }
            else if(array[j].weight <= min2){
                min2 = array[j].weight;
                l2 = j;
            }
        }
        array[i].weight = min1 + min2;
        array[l1].parent = array[l2].parent = i;
    }

    long long int ans(0),w;
    int p;
    for(int i(n);i<size;++i){
        p = array[i].parent; w = array[i].weight;
        while(p!=0){
            ans += w;
            p = array[p].parent;
        }
    }
    cout << ans;
    delete []array;
    return 0;
}

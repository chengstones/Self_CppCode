#include <iostream>
using namespace std;

const long long int MAX_VALUE = 9223372036854775807;

struct node{
    long long int weight;
    int parent;
    node():parent(0),weight(0){}
};

int main()
{
    long long int size; cin >> size;
    long long int length = 2 * size;
    long long int min1,min2;
    long long int s,t;
    node* elem = new node[length];
    for(int i(size);i<length;++i){
        cin >> elem[i].weight;
    }

    for(int i(size-1);i>0;--i){
        min1 = min2 =  MAX_VALUE;
        for(int j(i+1);j<length;++j){
            if (elem[j].parent == 0){
                if(elem[j].weight < min1){
                    min2 = min1;
                    min1 = elem[j].weight;
                    t = s;
                    s = j;
                }
                else if(elem[j].weight < min2){
                    min2 = elem[j].weight;
                    t = j;
                }
            }
        }
        elem[i].weight = min1 + min2;
        elem[s].parent = elem[t].parent = i;
    }

    long long int result(0);
    long long int floor(0);
    long long int w(0);
    int j;
    for(int i(size);i<length;++i){
        j = i;
        floor = -1;
        w = elem[i].weight;
        while(j!=0) {j = elem[j].parent;floor += 1;}
        result += w * floor;
    }
    cout << result;
    delete []elem;
    return 0;
}

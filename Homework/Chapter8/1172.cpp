#include <iostream>
using namespace std;

struct Node{
    int parent;
    int num;
    Node():parent(-1),num(1){}
};

void Union(Node* array,int x,int y){
    int tmp;


    while(array[x].parent != -1) x = array[x].parent;
    while(array[y].parent != -1) {
        tmp = array[y].parent;
        array[y].parent = x;
        y = tmp;}
    if ( x == y) return;
    array[y].parent = x;
}

bool Check(Node* array,int x,int y){
    while(array[x].parent != -1) x = array[x].parent;
    while(array[y].parent != -1) y = array[y].parent;
    return x == y;
}

int main()
{
    int N,M;
    cin >> N >> M;
    Node* array = new Node[N];

    int ope;
    int x,y;
    for(int i(0);i<M;++i){
        cin >> ope;
        switch(ope){
            case 1:{
                cin >> x >> y;
                --x;--y;
                Union(array,x,y);
            }
            break;
            case 2:{
                cin >> x >> y;
                --x;--y;
                if(Check(array,x,y)==1) cout << "Y\n"; else cout << "N\n";
            }
            break;
        }
    }
    delete []array;
    return 0;
}

#include <iostream>
using namespace std;

struct Node{
    int parent;
    Node():parent(-1){}
};

void rel(int* deep,int** fa,int x,int f){
    deep[x] = deep[f] + 1;
    fa[x][0] = f;
    for(int i(1);(1<<i)<=deep[x];++i)
        fa[x][i] = fa[fa[x][i-1]][i-1];
}

int lca(int* deep,int** fa,int x,int y){
    int ret;
    if(deep[x] < deep[y]) x^=y^=x^=y;
    for(int i(20);i>=0;i--)
        if(deep[fa[x][i]]>=deep[y])
            x = fa[x][i];
    if(x==y) return y;
    for(int i(20);i>=0;--i){
        if(fa[x][i]!=fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
        else ret = fa[x][i];
    }
    return ret;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int *deep = new int[n];
    int **fa = new int*[n];
    for(int i(0);i<n;++i) {
        deep[i] = 0;
        fa[i] = new int[21];
        for(int j(0);j<21;++j) fa[i][j] = 0;
    }
    
    Node* array = new Node[n];
    int x,y;
    for(int i(1);i<n;++i){
        cin >> x;
        rel(deep,fa,i,--x);
        array[i].parent = x;
    }

    
    int ans;
    for(int i(0);i<m;++i){
        cin >> x;
        cin >> ans;
        -- ans;
        for(int j(1);j<x;++j){
            cin >> y;
            ans = lca(deep,fa,--y,ans);    
        }
        cout << ans + 1 << endl;
    }
    return 0;
}

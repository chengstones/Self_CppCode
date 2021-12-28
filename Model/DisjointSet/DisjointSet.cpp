#include <iostream>
using namespace std;

class DisJointSet{
private:
    int size;
    int *parent;

public:
    DisJointSet(int s){
        size = n;
        parent = new int [size];
        for(int i(0);i<size;++i) parent[i] = -1;
    }
    ~DisJointSet(){delete []parent;}
    void Union(int root1, int root2){
        if(root1 == root2) return;
        if(parent[root1]>parent[root2]){
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
        else{
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
    }
    int Find(int x){
        if(parent[x]<0) return x;
        return parent[x] = Find(parent[x]);
    }
};

int main()
{
    
    system("pause");
    return 0;
}

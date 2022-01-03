#include <iostream>
using namespace std;


template <class Type>
class priorityQueue{
private:
    int currentSize;
    Type *array;
    int maxSize;

    void doubleSpace(){
        Type* delp(array);
        maxSize *= 2;
        array = new Type[maxSize];
        for(int i(1);i<=currentSize;++i){
            array[i] = delp[i];
        }
        delete []delp;
    }
    
    void percolateDown(int hole){
        int child;
        Type tmp = array[hole];

        for(;hole*2 <= currentSize; hole = child){
            child = hole * 2;
            if(child != currentSize && array[child+1] < array[child]){
                ++child;
            }
            if(array[child] < tmp) array[hole] = array[child];
            else break;
        }
        array[hole] = tmp;
    }

    void buildHeap(){
        for(int i(currentSize/2);i>0;--i){
            percolateDown(i);
        }
    }

public:
    priorityQueue(int capacity = 100){
        array = new Type[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    
    priorityQueue(const Type items[], int size):maxSize(size+10),currentSize(size){
        array = new Type[maxSize];
        for(int i(0);i<size;++i){
            array[i+1] = items[i];
        }
        buildHeap();
    }
    
    ~priorityQueue(){
        delete []array;
    }
    
    bool isEmpty() const{
        return currentSize == 0;
    }

    void enQueue(const Type &x){
        if(currentSize == maxSize - 1) doubleSpace();

        int hole = ++currentSize;
        for(;hole>1 && x < array[hole/2];hole/=2){
            array[hole] = array[hole/2];
        }
        array[hole] = x; // hole == 1  or  x >= array[hole/2]
    }

    Type deQueue(){
        Type minItem;
        minItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return minItem;
    }

    Type getHead() const{
        return array[1];
    }
};


class adjListGraph{
    private:
        int Vers, Edges;
        struct edgeNode{
            int end;
            int weight;
            edgeNode* next;
       
            edgeNode(int e,edgeNode *n = NULL,int w = 0)
            {end = e;next = n;weight = w;}
        };

        struct verNode{
            edgeNode* head;

            verNode(edgeNode *h = NULL){head = h;}
        };

        verNode *verList;

    public:
        adjListGraph(int vSize){
            Vers = vSize; Edges = 0;

            verList = new verNode[vSize];
        }
        ~adjListGraph(){
            int i;
            edgeNode* p;

            for(i = 0;i<Vers;++i){
                while((p=verList[i].head)!=NULL){
                    verList[i].head = p -> next;
                    delete p;
                }
            }
            delete []verList;
        }
        void insert(int x, int y,int w){
            edgeNode* p;
            for(p=verList[x].head;p!=NULL;p=p->next){
                if (p->end == y){
                    if (p->weight > w){
                        p -> weight = w;
                    }
                    return ;
                }
            }
            verList[x].head = new edgeNode(y,verList[x].head,w);
            ++Edges;
        }
        int prim(){
            bool *flag = new bool [Vers];
            int *lowCost = new int[Vers];
            int *startNode = new int[Vers];

            edgeNode* p;
            int min;
            int start,i,j;
            int result = 0;
            for(i = 0;i<Vers;++i){
                flag[i] = false;
                lowCost[i] = 2147483647;
            }

            start = 0;
            for(i=1;i<Vers;++i){
                for(p=verList[start].head;p!=NULL;p=p->next)
                    if(!flag[p->end]&&lowCost[p->end]>p->weight){
                        lowCost[p->end] = p->weight;
                        startNode[p->end] = start;
                    }
            flag[start] = true;
            min = 2147483647;
            for(j=0;j<Vers;++j)
                if(lowCost[j]<min){min=lowCost[j];start=j;}
                result += min;
                lowCost[start] = 2147483647;
            }
            return result;
        }
        
class DisJointSet{
private:
    int size;
    int *parent;

public:
    DisJointSet(int s){
        size =s;
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

        struct edge{
            int beg,end;
            int w;
            bool operator<(const edge&rp) const{return w < rp.w;}
        };
        int kruskal(){
            int edgesAccepted = 0,u,v;
            edgeNode *p;
            edge e;
            DisJointSet ds(Vers);
            priorityQueue<edge> pq;

            for(int i(0);i<Vers;++i){
                for(p=verList[i].head;p!=NULL;p=p->next)
                    if(i<p->end){
                        e.beg = i;
                        e.end = p->end;
                        e.w = p->weight;
                        pq.enQueue(e);
                    }
            }
            int result = 0;
            while(edgesAccepted<Vers-1){
                e = pq.deQueue();
                u = ds.Find(e.beg);
                v = ds.Find(e.end);
                if(u!=v){
                    edgesAccepted += 1;
                    ds.Union(u,v);
                    result += e.w;
                }
            }
            return result;
            
        }
};


int main(){
    int n,m;
    cin >> n >> m;
    adjListGraph q(n);
    int x, y, w;
    for(int i(0);i<m;++i){
        cin >> x >> y >> w;
        if(x == y) continue;
        q.insert(--x,--y,w);
        q.insert(y,x,w);
    }
    cout << q.kruskal();
    return 0;
}
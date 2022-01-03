#include <iostream>
using namespace std;

template <class elemType>
class queue{
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual ~queue(){}
};

template <class elemType>
class linkQueue:public queue<elemType>{
private:
    struct node{
        elemType data;
        node* next;
        node(const elemType &x, node* N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL){}
    };
    node *front, *rear;

public:
    linkQueue(){
        front = rear = NULL;
    }
    ~linkQueue(){
        node *delp;
        while(front){
            delp = front;
            front = front->next;
            delete delp;
        }
    }
    bool isEmpty() const{
        return front == NULL;
    }
    void enQueue(const elemType &x){
        if(rear == NULL) 
            front = rear = new node(x);
        else
            rear = rear -> next = new node(x);
    }
    elemType deQueue(){
        node* delp = front;
        elemType value = front -> data;
        front = front -> next;
        if(front == NULL) rear = NULL;
        delete delp;
        return value;
    }
    bool in(elemType x) const{
        for(node* p = front;p!=NULL;p=p->next){
            if (p->data == x) return true;
        }
        return false;
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
            verList[x].head = new edgeNode(y,verList[x].head,w);
            ++Edges;
        }
        void remove(int x,int y){
            edgeNode *p = verList[x].head, *q;

            if(p == NULL) return;

            if(p->end == y){
                verList[x].head = p->next;
                delete p; --Edges;
                return;
            }
            while(p->next!=NULL && p->next -> end != y) p = p->next;
            if(p->next != NULL){
                q = p -> next;
                p -> next = q -> next;
                delete q;
                --Edges;
            }
        }
        bool exist(int x, int y)const{
            edgeNode *p = verList[x].head;

            while(p!=NULL && p -> end!= y) p = p->next;
            if(p==NULL) return false;
            else return true;
        }
        int check(int start,int end){
            linkQueue<int> q;
            int* distance = new int[Vers];
            for(int i(0);i<Vers;++i){
                distance[i] =  2147483647;
            }
            distance[start] = 0;q.enQueue(start);
            int v;edgeNode* p;
            while(!q.isEmpty()){
                v = q.deQueue();
                for(p = verList[v].head;p!=NULL;p=p->next){
                    if(distance[v] + p->weight < distance[p->end]){
                        distance[p->end] = distance[v] + p->weight;
                        if(!q.in(p->end)) q.enQueue(p->end);                            
                    }
                }
            }
                return distance[end];
        }
};


int main(){
    int n,m,start,end;
    cin >> n >> m >> start >> end;

    adjListGraph q(n);

    int x, y, w;
    for(int i(0);i<m;++i){
        cin >> x >> y >> w;
        q.insert(--x,--y, w);
    }

    cout << q.check(--start,--end);
    return 0;
}
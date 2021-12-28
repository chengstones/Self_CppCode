#include <iostream>
#include <iomanip>
using namespace std;


template <class elemType>
class queue{
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() const = 0;
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
    elemType getHead() const{
        return front -> data;
    }
};

class adjListGraph{
    private:
        int Vers, Edges;
        struct edgeNode{
            int end;
            edgeNode* next;
       
            edgeNode(int e,edgeNode *n = NULL)
            {end = e;next = n;}
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
        void insert(int x, int y){
            verList[x].head = new edgeNode(y,verList[x].head);
            verList[y].head = new edgeNode(x,verList[y].head);
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
        double check(int i){
            linkQueue<int> q;
            int *distance = new int[Vers];
            int u,sNo;
            edgeNode *p;

            for(int i(0);i<Vers;++i) distance[i] = -1;

            sNo = i;
            distance[sNo] = 0;
            q.enQueue(sNo);

            while(!q.isEmpty()){
                u = q.deQueue();
                for(p = verList[u].head;p!=NULL;p=p->next){
                    if(distance[u] == 6) continue;
                    if(distance[p->end] == -1){
                        distance[p->end] = distance[u] + 1;
                        q.enQueue(p->end);
                    }
                }
            }
            int num(0);
            for(int i(0);i<Vers;++i){
                if(distance[i]!=-1) ++num;
            }
            return 100.0 * float(num) / float(Vers);
        }
};

int main(){
    int N,M; cin >> N >> M;
    adjListGraph g(N);
    int a,b;
    for(int i(0);i<M;++i){
        cin >> a >> b;
        g.insert(--a,--b);
    }
    double result;
    for(int i(0);i<N;++i){
        result = g.check(i);
        cout << i+1 << ": " << fixed << setprecision(2) << result << '%' << endl;
    }
}
#include <iostream>
#include <math.h>
using namespace std;


class adjListGraph{
    private:
        int Vers, Edges;
        struct edgeNode{
            int end;
            int w;
            edgeNode* next;
       
            edgeNode(int e,edgeNode *n = NULL, int w0 = 1)
            {end = e;next = n;w = w0;}
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
        void insert(int x, int y, int w){
            verList[x].head = new edgeNode(y,verList[x].head,w);
            verList[y].head = new edgeNode(x,verList[y].head,w);
            ++Edges;
        }

        int check_weight(int x, int y)const{
            edgeNode *p = verList[x].head;

            while(p!=NULL && p -> end!= y) p = p->next;
            return p->w;
        }
        int check() const{
            double *distance = new double[Vers];
            int *prev = new int[Vers];
            bool *known = new bool[Vers];

            int u,sNo,i,j;
            edgeNode *p;
            double min;
            for(i = 0;i<Vers;++i){
                known[i] = false;
                distance[i] = 2147483647;
            }

            sNo = 0;

            distance[sNo] = 0;
            prev[sNo] = 0;

            for(i = 1;i<Vers;++i){
                min = 2147483647;
                for(j = 0;j<Vers;++j){
                    if(!known[j]&&(distance[j]<min)){
                        min = distance[j];
                        u = j;
                    }
                }
            if (u == Vers - 1) break;
            known[u] = true;
            for(p = verList[u].head;p!=NULL;p=p->next){
                if(!known[p->end]&& distance[p->end] > min + log(p -> w)){
                    distance[p->end] = min + log(p->w);
                    prev[p->end] = u;
                }
            }
            }

            int son = Vers - 1;
            int parent = prev[Vers-1];
            long long int result = 1;
            while(son!=0){
                result *= check_weight(parent,son);
                result %= 998244353;
                son = parent;
                parent = prev[parent];
            }
            return result;
        }   
};


int main()
{
    int N,M; cin >> N >> M;
    adjListGraph G(N);
    int a,b,c;
    for(int i(0);i<M;++i){
        cin >> a >> b >> c;
        G.insert(--a,--b,c);
    }
    cout << G.check();
    return 0;
}

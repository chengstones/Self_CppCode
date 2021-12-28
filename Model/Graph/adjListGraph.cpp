#include <iostream>
#include "../Queue/linkQueue.cpp"
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class graph{
    public:
        virtual void insert(TypeOfVer x,TypeOfVer y, TypeOfEdge w) = 0;
        virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
        virtual bool exist(TypeOfVer  x, TypeOfVer y) const = 0;
        int numOfVer() const {return Vers;}
        int numOfEdge() const {return Edges;}

    protected:
        int Vers, Edges;
};

template<class TypeOfVer, class TypeOfEdge>
class adjListGraph:public graph<TypeOfVer,TypeOfEdge>{
    private:
        int Vers, Edges;
        struct edgeNode{
            int end;
            TypeOfEdge weight;
            edgeNode* next;
       
            edgeNode(int e,TypeOfEdge w,edgeNode *n = NULL)
            {end = e; weight = w;next = n;}
        };

        struct verNode{
            TypeOfVer ver;
            edgeNode* head;

            verNode(edgeNode *h = NULL){head = h;}
        };

        verNode *verList;
        int find(TypeOfVer v) const{
            for(int i(0);i<Vers;++i)
                if(verList[i].ver == v) return i;
            return -1;
        }

    
    public:
        adjListGraph(int vSize, const TypeOfVer d[]){
            Vers = vSize; Edges = 0;

            verList = new verNode[vSize];
            for(int i(0);i<Vers;++i) verList[i].ver = d[i];
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
        void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w){
            int u = find(x), v = find(y);
            verList[u].head = new edgeNode(v,w,verList[u].head);
            ++Edges;
        }
        void remove(TypeOfVer x,TypeOfVer y){
            int u = find(x), v = find(y);
            edgeNode *p = verList[u].head, *q;

            if(p == NULL) return;

            if(p->end == v){
                verList[u].head = p->next;
                delete p; -- Edges;
                return;
            }
            while(p->next!=NULL && p->next -> end != v) p = p->next;
            if(p->next != NULL){
                q = p -> next;
                p -> next = q -> next;
                delete q;
                --Edges;
            }
        }
        bool exist(TypeOfVer x, TypeOfVer y)const{
            int u = find(x), v = find(y);
            edgeNode *p = verList[u].head;

            while(p!=NULL && p -> end!= v) p = p->next;
            if(p==NULL) return false;
            else return true;
        }
        void dfs()const{
            bool *visited = new bool[Vers];

            for(int i(0);i<Vers;++i) visited[i] = false;

            for(int i(0);i<Vers;++i){
                if(visited[i]==true) continue;
                dfs(i,visited);
                cout << endl;
            }
        }

        void dfs(int start,bool visited[]) const{
            edgeNode* p = verList[start].head;

            cout << verList[start].ver << '\t';
            visited[start] = true;

            while(p!=NULL){
                if(visited[p->end]==false) dfs(p->end,visited);
                p = p->next;
            }
        }

        void bfs() const{
            bool *visited = new bool[Vers];
            int currentNode;
            linkQueue<int> q;
            edgeNode *p;

            for(int i(0);i<Vers;++i) visited[i] = false;

            for(int i(0);i<Vers;++i){
                if(visited[i]==true) continue;
                q.enQueue(i);
                while(!q.isEmpty()){
                    currentNode = q.deQueue();
                    if(visited[currentNode]==true) continue;
                    cout << verList[currentNode].ver << '\t';
                    visited[currentNode] = true;
                    p = verList[currentNode].head;
                    while(p!=NULL){
                        if(visited[p->end] == false) q.enQueue(p->end);
                        p = p->next;
                    }
                }
                cout << endl;
            }
        }
};

int main()
{
    adjListGraph<char,int> g(10,"abcdefghij");    
    g.insert('a','f',9);
    cout << g.exist('a','f') << endl;
    g.remove('a','f');
    cout << g.exist('a','f') << endl;
}
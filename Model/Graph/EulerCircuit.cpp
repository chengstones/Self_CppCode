#include <iostream>
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
        void EulerCircuit(TypeOfVer start){
            EulerNode *beg,*end,*p,*q,*tb,*te;
            int numOfDegree;
            edgeNode *r;
            verNode *tmp;

            if(Edges == 0){
                cout << "No Euler Circuit" << endl;
                return ;
            }
            for(int i(0);i<Vers;++i){
                numOfDegree = 0;
                r = verList[i].head;
                while(r!=0){
                    ++numOfDegree;
                    r = r->next;
                }
                if(numOfDegree % 2){
                    cout << "No Euler Circuit" << endl;
                    return ;
                }
            }

            i = find(start);
            tmp = clone();

            EulerCircuit(i,beg,end);
            while(true){
                p = beg;
                while(p->next != NULL){
                    if(verList[p->next->NodeNum].head != NULL) break;
                    else p = p -> next;
                }
                if(p->next == NULL) break;
                q = p -> next;
                EulerCircuit(q->NodeNum,tb,te);
                te -> next = q -> next;
                p -> next = tb;
                delete q;
            }
        }
};

int main()
{
    
    system("pause");
    return 0;
}

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


template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph: public graph<TypeOfVer,TypeOfEdge>{
    private:
        int Vers, Edges;
        TypeOfEdge **edge;
        TypeOfVer *ver;
        TypeOfEdge noEdge;
        int find(TypeOfVer v)const{
            for(int i(0);i<Vers;++i) if(ver[i] == v) return i;
            return -1;
        }
    
    public:

        adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag){
            int i,j;

            Vers = vSize;
            Edges = 0;
            noEdge = noEdgeFlag;

            ver = new TypeOfVer[vSize];
            for(i = 0;i<vSize;++i) ver[i] = d[i];

            edge = new TypeOfEdge *[vSize];
            for(i = 0;i<vSize;++i){
                edge[i] = new TypeOfEdge[vSize];
                for(j = 0;j<vSize;++j) edge[i][j] = noEdge;
                edge[i][j] = 0;
            }
        }
        ~adjMatrixGraph(){
            delete []ver;
            for(int i(0);i<Vers;++i) delete []edge[i];
            delete []edge;
        }
        void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w){
            int u = find(x), v = find(y);
            edge[u][v] = w;
            ++Edges;
        }
        void remove(TypeOfVer x, TypeOfVer y){
            int u = find(x), v = find(y);
            edge[u][v] = noEdge;
            --Edges;
        }
        bool exist(TypeOfVer x, TypeOfVer y) const{
            int u = find(x), v = find(y);
            if(edge[u][v] == noEdge) return false;
            else return true;
        }

};


int main()
{
    adjMatrixGraph<char,int> g(10,"abcdefghij",-1);    
    g.insert('a','f',9);
    cout << g.exist('a','f') << endl;
    g.remove('a','f');
    cout << g.exist('a','f') << endl;
}

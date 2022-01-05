#include <iostream>
using namespace std;

template <class KEY, class OTHER>
struct SET{
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class closeHashTable{
    private:
    struct node{
        SET <KEY,OTHER> data;
        int state;

        node(){state = 0;}
    };

    node* array;
    int size;
    int (*key) (const KEY &x);
    static int defaultKey(const int &x) {return x;}
    public:
        closeHashTable(int length = 101,int (*f)(const KEY&x) = defaultKey){
            size = length;
            array = new node[size];
            key = f;
        }
        ~closeHashTable(){delete []array;}
        SET<KEY,OTHER> *find(const KEY &x) const{
            int initPos,pos;

            initPos = pos = key(x)%size;
            do{
                if(array[pos].state==0) return NULL;
                if(array[pos].state==1&&array[pos].data.key == x){
                    return (SET<KEY,OTHER>*)&array[pos];
                }
                pos = (pos+1)%size;
            }while(pos!=initPos);
        }
        void insert(const SET<KEY,OTHER> &x){
            int initPos,pos;

            initPos = pos = key(x.key) % size;
            do{
                if(array[pos].state != 1){
                    array[pos].data = x;
                    array[pos].state = 1;
                    return;
                }
                pos = (pos + 1) % size;
            } while(pos != initPos);
        }
        void remove(const KEY &x){
            int initPos,pos;

            initPos = pos = key(x) % size;
            do{
                if(array[pos].state == 0) return;
                if(array[pos].state == 1 && array[pos].date.key == x){
                    array[pos].state == 2;
                    return ;
                }
                pos = (pos + 1) % size;
            } while(pos != initPos);
        }        
};

template <class KEY, class OTHER>
class openHashTable{
private:
    struct node{
        SET<KEY,OTHER> data;
        node *next;

        node(const SET<KEY,OTHER> &d, node* n = NULL){data = d;next = n;}
        node() {next = NULL;}
    };

    node**  array;
    int size;
    int (*key)(const KEY &x);
    static int defaultKey(const int &x){return x;}

public:
    openHashTable(int length = 101,int (*f)(const KEY &x) = defaultKey){
        size = length;
        array = new node*[size];
        key = f;
        for(int i(0);i<size;++i) array[i] = NULL;
    }
    ~openHashTable(){
        node * p, * q;

        for(int i(0);i<size;++i){
            p = array[i];
            while(p!=NULL) {q = p->next;delete p;p=q;};
        }

        delete []array;
    }

    SET<KEY,OTHER> *find(const KEY &x) const{
        int pos;
        node* p;

        pos = key(x) % size;
        p = array[pos];
        while(p!=NULL && !(p->data.key == x)) p = p->next;
        if(p==NULL) return NULL;
        else return (SET<KEY,OTHER>*) p;
    }
    
    
    void insert(const SET<KEY,OTHER> &x){
        int pos;
        node *p;

        pos = key(x.key) % size;
        array[pos] = new node(x,array[pos]);
    }

    void remove(const KEY &x){
        int pos;
        node *p, *q;

        pos = key(x) % size;
        if(array[pos] == NULL) return ;
        p = array[pos];
        if(array[pos] -> data.key == x){
            array[pos] = p -> next;
            delete p;
            return ;
        }
        while(p->next != NULL && !(p->next -> data.key == x)) p = p->next;
        if(p->next != NULL){
            q = p->next;
            p -> next = q -> next;
            delete q;
        }
    }
};

int main()
{
    
    system("pause");
    return 0;
}

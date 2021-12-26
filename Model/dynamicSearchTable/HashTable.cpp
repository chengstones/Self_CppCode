#include <iostream>
using namespace std;

template <class KEY, class OTHER>
struct SET{
    KEY key;
    OTHER other;
};

template <class KTY, class OTHER>
class closeHashTable{
    private:
    struect node{
        SET <KEY,OTHER> data;
        int state;

        node(){state = 0;}
    };

    node* array;
    int size;
    int (*key) (const KEY &x);
    static int defaultKey(const int &x) {return x;}
    public:
        closeHashTable(int length = 101,int (*f)(const KEY&x) = defaultKEY){
            size = length;
            array = new node[size];
            key = f;
        }
        ~closeHashTable(){delete []array;}
        SET<KEY,OTHER> *find(const KEY &x) const;
        void insert(const SET<KEY,OTHER> &x);
        void remove(const KEY &x);
};

int main()
{
    
    system("pause");
    return 0;
}

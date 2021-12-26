#include <iostream>
using namespace std;

template <class KEY, class OTHER>
struct SET{
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class BinarySearchTree{
private:
    struct BinaryNode{
        SET<KEY,OTHER> data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const SET<KEY, OTHER>& thedata, 
            BinaryNode* lt = NULL, BinaryNode* rt = NULL):
            data(thedata),left(lt),right(rt){}
        BinaryNode* root;
    };
    BinaryNode* root;

public:
    BinarySearchTree(){
        root = NULL;
    }
    ~BinarySearchTree(){
        makeEmpty(root);
    }
    SET<KEY,OTHER> * find(const KEY &x) const{
        return find(x,root);
    }
    void insert(const SET<KEY,OTHER> &x){
        insert(x,root);
    }
    void remove(const KEY & x){
        remove(x,root);
    }

private:
    void insert(const SET<KEY,OTHER> &x, BinaryNode* &t){
        if(t == NULL)
            t = new BinaryNode(x,NULL,NULL);
        else if(x.key < t->data.key)
            insert(x,t->left);
        else if(t->data.key < x.key)
            insert(x,t->right);
    }
    void remove(const KEY &x, BinaryNode* &t){
        if (t == NULL) return;
        if(x < t->data.key) remove(x,t->left);
        else if(t -> data.key < x) remove(x,t->right);
        else{
            if (t -> left && t -> right){
                // Two children
                BinaryNode* tmp = t -> right;
                while(tmp ->left) tmp = tmp -> left;
                t -> data = tmp -> data;
                remove(t->data.key, t -> right);
            }
            else{
                // one child or none
                BinaryNode *oldNode = t;
                t = (t->left) ? t -> left:t->right;
                delete oldNode;
            }
        }
    }
    SET<KEY,OTHER> * find(const KEY &x,BinaryNode*t) const{
        if(t == NULL || t -> data.key == x)
            return &(t -> data);
            //return (SET<KEY,OTHER>*)t;
        if(x<t->data.key) return find(x,t->left);
        else return find(x,t->right);
    }
    void makeEmpty(BinaryNode *t){
        if(t == NULL) return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
};

int main()
{
    SET<int,char*>a[] = {{10,"aaa"},{8,"bbb"},{21,"ccc"},{87,"ddd"},{56,"eee"},{4,"fff"},{11,"ggg"}};
    BinarySearchTree<int,char*> tree;
    SET<int,char*> x;
    SET<int,char*> *p;

    for(int i(0);i<7;++i) tree.insert(a[i]);

    p = tree.find(56);
    if(p) cout << p -> key << ' ' << p->other << endl;
    else cout << "NOT FOUND" << endl;
    p = tree.find(21);
    if(p) cout << p -> key << ' ' << p->other << endl;
    else cout << "NOT FOUND" << endl;
    tree.remove(21);
    p = tree.find(21);
    if(p) cout << p -> key << ' ' << p->other << endl;
    else cout << "NOT FOUND" << endl;
    x.key = 30;x.other = "xyz";
    tree.insert(x);
    p = tree.find(30);
    if(p) cout << p -> key << ' ' << p->other << endl;
    else cout << "NOT FOUND" << endl;
    
    return 0;
}
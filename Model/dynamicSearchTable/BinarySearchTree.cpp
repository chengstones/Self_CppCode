#include <iostream>
using namespace std;

template <class KEY, class OTHER>
class BinarySearchTree{
private:
    struct SET{
        KEY key;
        OTHER other;
    }
    struct BinaryNode{
        SET<KEY,OTHER> data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const SET<KEY, OTHER>& thedata, BinaryNode* lt = NULL, BinaryNode* rt = NULL):data(thedata),left(lt),right(rt){}
        BinaryNode* root;
    };

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
    SET<KEY,OTHER> * find(const KEY &x) const{
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
    system("pause");
    return 0;
}



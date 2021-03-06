#include <iostream>
#include "../Queue/Queue.cpp"
using namespace std;

template<class T>
class bTree{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T lchild(T x, T flag) const = 0;
    virtual T rchild(T x, T flag) const = 0;
    virtual void delLeft(T x) = 0;
    virtual void delRight(T x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
};

template<class T>
class binaryTree:public bTree<T>{
private:
    struct Node{
        Node *left, *right;
        T data;

        Node():left(NULL),right(NULL){}
        Node(T item, Node *L = NULL, Node *R = NULL):data(item),left(L),right(R){}
        ~Node(){}
    };
    Node *root; 

public:
    binaryTree():root(NULL){}
    binaryTree(T x){root = new Node(x);}
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    T parent(T x, T flag) const{return flag;}
    void printTree(T flag) const;
private:
    Node* find(T x, Node *t) const;
    void clear(Node* &t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node* t) const;
    void levelOrder(Node* t) const;
};


template <class T>
bool binaryTree<T>::isEmpty() const{
    return root == NULL;
}

template <class T>
T binaryTree<T>::Root(T flag) const{
    if(root == NULL) return flag;
    else return root -> data;
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t){
    if(t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template <class T>
void binaryTree<T>::clear(){
    clear(root);
}

template <class T>
binaryTree<T>::~binaryTree(){
    clear(root);
}

template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node* t) const{
    if(t == NULL) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder() const{
    cout << "\n ????????????";
    preOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node* t) const{
    if(t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}

template <class T>
void binaryTree<T>::postOrder() const{
    cout << "\n ????????????";
    postOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node* t) const{
    if(t == NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder() const{
    cout << "\n ????????????";
    midOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder() const{
    linkQueue<Node *> que;
    Node* tmp;

    cout << "\n ????????????";
    que.enQueue(root);

    while(!que.isEmpty()){
        tmp = que.deQueue();
        cout << tmp->data << ' ';
        if(tmp->left) que.enQueue(tmp->left);
        if(tmp->right) que.enQueue(tmp->right);
    }
}

template <class T>
typename binaryTree<T>::Node *binaryTree<T>::find(T x, binaryTree<T>::Node *t) const{
    Node* tmp;
    if(t == NULL) return NULL;
    if(t->data == x) return t;
    if(tmp = find(x,t->left)) return tmp;
    else return find(x,t->right);
}

template <class T>
void binaryTree<T>::delLeft(T x){
    Node* tmp = find(x,root);
    if(tmp == NULL) return;
    clear(tmp -> left);
}

template <class T>
void binaryTree<T>::delRight(T x){
    Node* tmp = find(x,root);
    if(tmp == NULL) return;
    clear(tmp -> right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const{
    Node* tmp = find(x,root);
    if(tmp == NULL||tmp->left == NULL) return flag;

    return tmp -> left -> data; 
}

template <class T>
T binaryTree<T>::rchild(T x,T flag) const{
    Node* tmp = find(x,root);
    if(tmp == NULL||tmp->right == NULL) return flag;

    return tmp -> right -> data;
}

template <class T>
void binaryTree<T>::printTree(T flag) const
{
    linkQueue<T> q;
    q.enQueue(root->data);
    cout << endl;
    while (!q.isEmpty()) {
        T p,l,r;
        p = q.deQueue();
        l = lchild(p,flag);
        r = rchild(p,flag);
        cout << p << ' ' << l << ' ' << r <<endl;
        if (l != flag) q.enQueue(l);
        if (r != flag) q.enQueue(r);
    }
}

template <class T>
void binaryTree<T>::createTree(T flag){
    linkQueue<Node*> que;
    Node* tmp;
    T x, ldata, rdata;
    // ??????????????????flag ????????????
    cout << "\n ??????????????????";
    cin >> x;
    if( x == flag){root = NULL;return;}
    root = new Node(x);
    que.enQueue(root);

    while(!que.isEmpty()){
        tmp = que.deQueue();
        cout << "\n ??????" << tmp -> data << "???????????????(" << flag << " ???????????????): ";
        cin >> ldata >> rdata;
        if(ldata != flag) que.enQueue(tmp -> left = new Node(ldata));
        if(rdata != flag) que.enQueue(tmp -> right = new Node(rdata));
    }

    cout << "create completed! \n";
}



// ???????????????
void preOrder() const{
    linkStack<Node *> s;

    Node *current;

    s.push(root);
    while(!s.isEmpty()){
        current = s.pop();
        cout << current -> data;
        if(current -> right != NULL) s.push(current -> right);
        if(current -> left != NULL) s.push(current -> left);       
    }
}
// ???????????????
struct stNode{
    Node* node;
    int TimesPop;

    stNode(Node* N = NULL):node(N),TimesPop(0){}
}

void midOrder() const{
    linkStack<stNode> s;
    stNode current(root);
    s.push(current);
    while(!s.isEmpty()){
        current = s.pop();
        if(++current.TimesPop == 1){
            s.push(current);
            if(current.node -> left != NULL)
                s.push(stNode(current.node -> left));
        }
        else{
            cout << current.node -> data;
            if (current.node -> right != NULL)
                s.push(stNode(current.node -> right));
        }
    }
}

void postOrder() const{
    linkStack<stNode> s;
    stNode current(root);
    s.push(current);
    while(!s.isEmpty()){
        current = s.pop();
        if(++current.TimesPop == 1){
            s.push(current);
            if (current.node -> right != NULL)
                s.push(stNode(current.node -> right));
            if(current.node -> left != NULL)
                s.push(stNode(current.node -> left));
        }
        else{
            cout << current.node -> data;
        }
    }
}

// ?????????????????????????????????
template <class elemType>
Node<elemType> *BTree<elemType>::buildTree(
    elemType pre[],int pl,int pr,
    elemType mid[],int ml,int mr
){
    Node<elemType>*p,*leftRoot,*rightRoot;
    int i,pos,num;
    int lpl,lpr,lml,lmr;
    int rpl,rpr,rml,rmr;
    if(pl>pr) return NULL;
    p = new Node<elemType>(pre[pl]); // ??????????????????
    if(!root) root = p;

    for(i = ml;i<=mr;++i){
        if(mid[i]==pre[pl]break;)
    }// ??????????????????????????????
    pos = i;
    num = pos - ml; // ?????????????????????????????????

    // ????????????????????????????????????????????????
    lpl = pl + 1; lpr = pl + num;
    lml = ml; lmr = pos - 1;
    leftRoot = buildTree(pre,lpl,lpr,mid,lml,lmr);

    // ????????????????????????????????????????????????
    rpl = pl + num + 1; rpr = pr;
    rml = pos + 1; rmr = mr;
    rightRoot = buildTree(pre,rpl,rpr,mid,rml,rmr);

    p -> left = leftRoot;
    p -> right = rightRoot;
}

// ?????????????????????????????????
template <class elemType>
Node<elemType> *BTree<elemType>::buildTree(
    elemType post[],int pl,int pr,
    elemType mid[],int ml,int mr
){
    Node<elemType>*p,*leftRoot,*rightRoot;
    int i,pos,num;
    int lpl,lpr,lml,lmr;
    int rpl,rpr,rml,rmr;
    if(pl>pr) return NULL;
    p = new Node<elemType>(pre[pr]); // ??????????????????
    if(!root) root = p;

    for(i = ml;i<=mr;++i){
        if(mid[i]==pre[pr]break;)
    }// ??????????????????????????????
    pos = i;
    num = pos - ml; // ?????????????????????????????????

    // ????????????????????????????????????????????????
    lpl = pl; lpr = pl + num;
    lml = ml; lmr = pos - 1;
    leftRoot = buildTree(pre,lpl,lpr,mid,lml,lmr);

    // ????????????????????????????????????????????????
    rpl = pl + num; rpr = pr - 1;
    rml = pos + 1; rmr = mr;
    rightRoot = buildTree(pre,rpl,rpr,mid,rml,rmr);

    p -> left = leftRoot;
    p -> right = rightRoot;
}
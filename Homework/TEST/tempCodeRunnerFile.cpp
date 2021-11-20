#include <iostream>
using namespace std;

struct Node{
    Node *left, *right;
    char data;

    Node():left(NULL),right(NULL){}
    Node(char item, Node *L = NULL, Node *R = NULL):data(item),left(L),right(R){}
    ~Node(){}
};

Node* buildTree(
    char pre[],int pl,int pr,
    char mid[],int ml,int mr
){
    Node*p,*leftRoot,*rightRoot;
    int i,pos,num;
    int lpl,lpr,lml,lmr;
    int rpl,rpr,rml,rmr;
    if(pl>pr) return NULL;
    p = new Node(pre[pl]); // 找到子数的根

    for(i = ml;i<=mr;++i){
        if(mid[i]==pre[pl]) break;
    }// 找到根在中序中的位置
    pos = i;
    num = pos - ml; // 找到左子树中的节点个数

    // 找左子树的前序，中序序列下标范围
    lpl = pl + 1; lpr = pl + num;
    lml = ml; lmr = pos - 1;
    leftRoot = buildTree(pre,lpl,lpr,mid,lml,lmr);

    // 找右子树的前序，中序序列下标范围
    rpl = pl + num + 1; rpr = pr;
    rml = pos + 1; rmr = mr;
    rightRoot = buildTree(pre,rpl,rpr,mid,rml,rmr);

    p -> left = leftRoot;
    p -> right = rightRoot;
    return p;
}

template <class elemType>
class linkQueue{
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

int main()
{
    char *pre = new char[27];
    cin >> pre;

    int size(0);
    for(;pre[size] != '\0';++size);

    char *mid = new char[size + 1];
    cin >> mid;

    Node* root;
    root = buildTree(pre,0,size-1,mid,0,size-1);

    linkQueue<Node*> st;
    Node* p;
    st.enQueue(root);
    while(size){
        p = st.deQueue();
        if (p == NULL) {cout << "NULL ";st.enQueue(NULL);st.enQueue(NULL);} 
        else {cout << p->data << ' '; --size;st.enQueue(p->left);st.enQueue(p->right);}   
    }
    
    delete []pre;
    delete []mid;
    return 0;
}

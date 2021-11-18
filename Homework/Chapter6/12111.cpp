#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int D, Node* L = NULL, Node* R = NULL):data(D),left(L),right(R){}
};

struct stNode{
    Node* node;
    int TimesPop;

    stNode(Node* N = NULL):node(N),TimesPop(0){}
};

void remove(Node* root, int data){
    if(root == NULL) return;
    if(root -> data < data) remove(root -> right,data);
    else if(data < root -> data) remove(root -> left,data);
    else{
        if(root -> left && root -> right){
            Node* tmp = root -> right;
            while(tmp -> left) tmp = tmp -> left;
            root -> data = tmp -> data;
            remove(root -> right, root -> data);
        }
        else{
            Node *oldNode = root;
            root = (root->left)? root->left:root->right;
            delete oldNode;
        }
    }
}

template <class elemType>
class linkStack{
private:
    struct Node{
        elemType data;
        Node* next;
        Node(const elemType &x,Node* n = NULL){
            data = x;
            next = n;
        }
        Node():next(NULL){}
        ~Node(){}
    };
    Node* top_p;

public:
    linkStack(){top_p = NULL;}
    ~linkStack(){
        Node* delp;
        while(top_p){
            delp = top_p;
            top_p = top_p ->next;
            delete delp;
        }
    }
    bool isEmpty() const{
        return top_p == NULL;
    }
    void push(const elemType &x){
        Node* n = new Node(x,top_p);
        top_p = n;
    }
    elemType pop(){
        bool flag(top_p == NULL);
        Node* delp = top_p;
        top_p = top_p -> next;
        elemType ans(delp -> data);
        delete delp;
        return ans;
    }
    elemType top() const{
        return top_p -> data;
    }
};

int main()
{
    int M; cin >> M;
    int opt, ipt;
    Node* root = NULL,*p;
    for(int i(0);i<M;++i){
        cin >> opt;
        switch(opt){
            case 1:{
                cin >> ipt;
                p = root;
                while(true){
                    if(p == NULL) p = new Node(ipt);
                    if(p->data < ipt) {p = p -> right;continue;}
                    if(ipt < p->data) {p = p -> left; continue;}
                }
            } break;
            case 2:{
                cin >> ipt;
                remove(root,ipt);
            } break;
            default:{
                int MIN = 2147483647;
                cin >> ipt;
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
                        if(ipt == current.node -> data) {MIN = 0;break;}
                        if(ipt < current.node -> data) {MIN = (MIN > current.node -> data - ipt)? current.node -> data - ipt:MIN; break;}
                        if(current.node -> data < ipt) {MIN = current.node -> data - ipt;}
                        if (current.node -> right != NULL)
                            s.push(stNode(current.node -> right));
                    }
                }
                cout << MIN << endl;
            }
        }
    }
}   



#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int D, Node* L = NULL, Node* R = NULL):data(D),left(L),right(R){}
};


void remove(Node* &root, int data){
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

int min_abs(Node* root, int ipt){
    if (root -> data == ipt) return 0;
    if (root -> data < ipt){
        int min1 = ipt - root -> data;
        if(!root -> right) return min1;
        int min2 = min_abs(root -> right,ipt);
        return (min1 > min2)? min2:min1;
    }
    if (ipt < root -> data){
        int min1 = root -> data - ipt;
        if(!root -> left) return min1;
        int min2 = min_abs(root -> left,ipt);
        return (min1 > min2)? min2:min1;
    }
}

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
                if(root == NULL) root = new Node(ipt);
                else{
                    p = root;
                    while(true){
                        if(p->data < ipt){if (p -> right) p = p -> right;else{ p -> right = new Node(ipt);break;}continue;}
                        if(ipt < p->data){if (p -> left) p = p -> left;else{ p -> left = new Node(ipt);break;}continue;}
                    }
                }
            } break;
            case 2:{
                cin >> ipt;
                remove(root,ipt);
            } break;
            default:{
                cin >> ipt;
                cout << min_abs(root,ipt) << '\n';
            }
        }
    }
    return 0;
}   



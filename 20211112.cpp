template<class KEY, class OTHER>
bool dynamicSearchTree<KEY, OTHER>::find(const KEY &x){
    Node* p = root;
    while(p!=NULL){
        if(p->key == x) return true;
        else if(p->key > x){
            p = p -> left;
            continue;
        }
        else p = p -> right;
    }
    return false;
}


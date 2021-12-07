    linkQueue<Node*> st;
    Node* p;
    st.enQueue(root);
    while(size){
        p = st.deQueue();
        if (p == NULL) {cout << "NULL ";st.enQueue(NULL);st.enQueue(NULL);} 
        else {cout << p->data << ' '; --size;st.enQueue(p->left);st.enQueue(p->right);}   
    }
struct node
{
    int val;
    int npl;
    node *left, *right;

    node(int x = 0, node* p = NULL, node* q = NULL) :val(x), left(p), right(q) {}
};
// The function of this function is 
//return the root of the new tree which is merged by tree1 and tree2
node* merge(node* root1, node* root2)
{
    //recursion basis
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;
    node *l, *r;
    // r merge with l->right
    root1->val < root2->val ? (l = root1, r = root2) : (l = root2, r = root1);

    l->right = merge(l->right, r);

    if (l->left == NULL || l->right->npl > l->left->npl)
        swap(l->right, l->left);

    l->npl = l->left->npl + 1;

    return l;
}
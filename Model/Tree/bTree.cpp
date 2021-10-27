#include <iostream>
#include "bTree_realize.cpp"
using namespace std;

int main()
{
   binaryTree<char> Tree;
   Tree.createTree('0');
   Tree.preOrder();
   Tree.midOrder();
   Tree.postOrder();
   Tree.printTree('@');

   return 1;
}

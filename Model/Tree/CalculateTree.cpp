#include <iostream>
#include "../stack/Stack.cpp"
using namespace std;

class CaculateTree{
private:
    struct Node{
        char data;
        Node* left, *right;
        Node(char thedata, Node* l = NULL, Node* r = NULL):data(thedata),left(l),right(r){}
        ~Node(){}
    }
    Node* root;
    linkStack<Node> s;
public:
    CaculateTree(){root = NULL;}
    ~CaculateTree(){}
    char alpha,operator;
    int a1,a2;
    void generator(){
        while(!cin.get(alpha)){
            if('0' <= alpha && alpha <= '9'){
                s.push(Node(alpha));
            }
            else{
                if(alpha == ')'){
                    while(s.top()!='('){
                        operator = t.pop();
                        a1 = s.pop().data
                    }
                }
            }
        }
    }
};

int main()
{
    
    system("pause");
    return 0;
}

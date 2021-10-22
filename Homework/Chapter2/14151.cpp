#include <iostream>

using namespace std;

class seqstack{
private:
    int* elem;
    int Top;
    int maxSize;

    void doubleSpace();

public:
    seqstack(int initSize = 10);
    ~seqstack();
    int pop();
    void push(const int &x);
};


void seqstack::doubleSpace(){
    int* new_elem = new int[maxSize*2];
    for(int i(0);i<maxSize;++i){
        new_elem[i] = elem[i];
    }
    maxSize *= 2;
    delete []elem;
    elem = new_elem;
}


seqstack::seqstack(int init_size){
    maxSize = init_size;
    elem = new int[maxSize];
    Top = 0;
}

seqstack::~seqstack(){
    delete []elem;
}



int seqstack::pop(){
    if(Top == 0) throw -1;
    --Top;
    return elem[Top+1];
}

void seqstack::push(const int &x){
    ++Top;
    if(Top==maxSize){
        doubleSpace();
    }
    elem[Top] = x;
}

int main(){
    int num; cin >> num;
    int N,now_N,n;
    seqstack* stack;
    for (int i(0);i<num;++i){
        cin >> N;now_N = 0;
        stack = new seqstack(N);
        int j = 0;
        for (;j<N;++j){
            cin >> n;
            if(now_N < n){
                while(now_N < n) stack->push(++now_N);
                stack -> pop();
                continue;
            }
            if (now_N >= n){
                if (stack->pop() == n) continue;
                cout << "No" << endl;
                for(;j<N-1;++j){
                    cin >> n;
                }
                break;
            }
        }
        if (j==N) cout << "Yes" << endl;
        delete stack;
    }
}


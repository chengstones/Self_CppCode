// 后缀表达式
/*
所谓后缀表达式是指这样的一个表达式：式中不再引用括号，运算符号放在两个运算对象之后，所有计算按运算符号出现的顺序，严格地由左而右新进行（不用考虑运算符的优先级）。

如：3*(5–2)+7对应的后缀表达式为：3.5.2.-*7.+@。’@’为表达式的结束符号。‘.’为操作数的结束符号。

注：仅包含-、+、*、/运算，其中/是整除。操作数均是int范围内正整数且计算过程中不会超过int范围。

输入格式
一行一个字符串，表示后缀表达式。

输出格式
一行一个整数，表示表达式的值
*/

#include <iostream>
using namespace std;


class seqStack{
private:
    int* elem;
    int currentLength;
    int maxSize;
    void doubleSpace(){
        int* tmp = elem;
        maxSize *= 2;
        elem = new int[maxSize];
        for(int i(0);i<currentLength;++i){
            elem[i] = tmp[i];
        }
        delete []tmp;
    }

public:
    seqStack(int initSize = 10){
        maxSize = initSize;
        currentLength = 0;
        elem = new int[maxSize];
    }
    ~seqStack(){delete []elem;}
    bool isEmpty() const{return currentLength == 0;}
    void push(int x){
        if (currentLength == maxSize) doubleSpace();
        ++currentLength;
        elem[currentLength - 1] = x;
    }
    int pop(){
        --currentLength;
        return elem[currentLength];
    }
    int top() const{
        return elem[currentLength - 1];
    }
};

int main(){
    char x;
    int num;
    int a,b;
    seqStack S(4);
    while(cin.get(x)){
        if(x == '@') break;
        num = 0;
        if('0'<=x&&x<='9'){
            num += x - '0';
            while(cin.get(x)){
                if(x == '.') break;
                num = num*10 + (x - '0');
            }
            S.push(num);
        }
        else{
            b = S.pop();a = S.pop();
            switch(x){
                case '+':S.push(a+b);break;
                case '-':S.push(a-b);break;
                case '*':S.push(a*b);break;
                case '/':S.push(a/b);break; // 执行减法和除法顺序是反的
            }
        }
    }
    cout << S.top();
    return 0;
}
// 字符串相加
// 给定两个字符串（str1和str2），求它们相加的“和”

/*
给定字符串

str1=“123”
str2=“456”
它们的“和”是“579”

注意“进位”的情况，如给定字符串

str1=“1”
str2=“99”
它们的“和”是“001”
*/

/*
Note:

字符串中的所有字符均在‘0’-‘9’之间

”和“仍为字符串（注意不能是数字）

输入有三行：

第一行为两个数字（m和n），用空格隔开，分别表示str1和str2的长度，注意长度包含字符串的结束字符'\0'，所有字符串长度均大于1
第二行为字符串str1
第三行为字符串str2
返回有一行：

字符串的“和”
*/
#include <iostream>
using namespace std;

char* add_two_string(char *p, char *q, int len1, int len2){
    if(len1>len2) return add_two_string(q,p,len2,len1);
    char* ans = new char[len2+1];
    int a,s(0);
    for(int i(0);i<len1-1;++i){
        a = (p[i]-'0')+(q[i]-'0')+s;
        s = a / 10;
        ans[i] = '0' + a % 10;
    }
    for(int i(len1-1);i<len2-1;++i){
        a = (q[i]-'0') + s;
        s = a / 10;
        ans[i] = '0' + a % 10;
    }
    switch (s){
        case 0: ans[len2-1] = '\0';break;
        case 1: ans[len2-1] = '1'; ans[len2] = '\0';break;
    }
    return ans;
}

int main(){
    int len1,len2;
    cin >> len1 >> len2;
    char* p = new char[len1];
    char* q = new char[len2];
    cin >> p >> q;

    char* ans = add_two_string(p,q,len1,len2);
    cout << ans;
    delete []p;
    delete []q;
    delete []ans;
    return 0;
}


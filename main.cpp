#include<iostream>
#include<set>
using namespace std;

int main()
{
set<int> s1;
int num, op, x;
int min1,min2;
set<int>::iterator it1;
set<int>::iterator it2;
cin >> num;
for(int i = 0;i<num;++i){
cin >> op >> x;
switch (op){
case 0:
it1 = s1.begin(); it2 = s1.end(); --it2;
if(x >= *it2){cout << x- *it2 << endl;}
else if(x <= *it1){cout <<*it1 - x << endl;}
else{
min1 = *s1.lower_bound(x) - x ;
min2 = x - *s1.upper_bound(x);
if(min1 < min2)
cout << min1 << endl;
else
cout << min2 << endl;}
break;
case 1:
s1.insert(x);
break;
case 2:
s1.erase(x);
break;
}
}
return 0;
}
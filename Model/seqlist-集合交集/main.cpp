#include <iostream>
#include "seqlist.h"
using namespace std;

int main()
{
    seqList<int> list1(20),list2(20),list3(20);
    int i, j, x;
    int len1,len3;

    i=1;
    cin>>x;

    while (x!=0)
    {
        list1.insert(i,x);
        i++;
        cin>>x;
    }

    i=1;
    cin>>x;

    while (x!=0)
    {
        list2.insert(i,x);
        i++;
        cin>>x;
    }

    len1 = list1.length();
    j=1;
    for (i=1; i<=len1; i++)
    {
        x=list1.get(i);
        if (list2.find(x)!=0)
        {
            list3.insert(j,x);
            j++;
        }
    }

    len3 = list3.length();
    for (i=1; i<=len3; i++)
    {
        x=list3.get(i);
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

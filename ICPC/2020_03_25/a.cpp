#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int main()
{
    int h,w,d;
    cin>>h>>w>>d;
    int anc=0;
    if(h-2*d<=0||w-2*d<=0)anc=0;
    else anc=(h-2*d)*(w-2*d);
    cout<<anc;
    return 0;
}
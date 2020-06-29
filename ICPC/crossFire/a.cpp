#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int main()
{
    int a[5];
    for(int i=1;i<=4;i++){
        cin>>a[i];
    }
    sort(a+1,a+5);
    cout<<abs(a[1]+a[4]-a[2]-a[3]);
    return 0;
}
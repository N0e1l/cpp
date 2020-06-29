#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int c=a%b;
        if(c)c=b-c;
        cout<<c<<endl;
    }
    return 0;
}
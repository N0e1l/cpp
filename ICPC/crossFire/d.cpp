#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int main()
{
    int t;
    cin>>t;
    if(t==1){
        cout<<"1\n1";
    }
    else if(t==2){
        cout<<"2\n";
        cout<<"0\n11";
    }
    else{
        cout<<t-1<<endl;
        for(int i=1;i<=t-1;++i){
            cout<<"1";
            for(int j=1;j<=i-1;++j)cout<<"0";
            cout<<"1";
            cout<<endl;
        }
    }
    return 0;
}
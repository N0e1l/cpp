#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
LL a[60];
void soive(){
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=55;i++){
        a[i]=a[i-1]+a[i-2];
    }
}

int main()
{
    int T;
    cin>>T;
    soive();
    while(T--){
        int n,m;
        cin>>n>>m;
        cout<<a[m-n+1]<<endl;
    }
    return 0;
}
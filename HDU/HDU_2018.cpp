#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
LL a[60];
void soive(){
    a[1]=1,a[2]=2,a[3]=3;
    for(int i=4;i<=55;i++){
        a[i]=a[i-1]+a[i-3];
    }
}
int main()
{
    int n;
    soive();
    while(cin>>n&&n){
        cout<<a[n]<<endl;
    }
    return 0;
}
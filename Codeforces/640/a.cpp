#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int a[10]={0};
        int cnt=0;
        int p=10;
        while(num){
            a[cnt++]=num%p;
            num/=p;
        }
        int cc=0;
        for(int i=0;i<cnt;i++){
            if(a[i]!=0)cc++;
        }
        cout<<cc<<endl;
        for(int i=0;i<cnt;i++){
            if(a[i]!=0){cout<<a[i];for(int j=1;j<=i;j++)cout<<"0";cout<<" ";}
        }
        cout<<endl;
    }
    return 0;
}
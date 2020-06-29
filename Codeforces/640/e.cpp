#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
 
int n;
int prSum[8010];
int data[8010];
int pd[8010];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        fill(prSum,prSum+1+n,0);
        memset(pd,0,sizeof(pd));
        for(int i=1;i<=n;++i){
            cin>>data[i];
            prSum[i]=prSum[i-1]+data[i];
        }
        for(int i=0;i<=n;++i){
            for(int j=i+2;j<=n;++j){
                pd[prSum[j]-prSum[i]]=1;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(pd[data[i]])cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
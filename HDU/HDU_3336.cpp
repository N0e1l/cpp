#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
const int N=10e6+10;
char s[N];
int fail[N];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int len;
        cin>>len>>s+1;
        fail[1]=0;
        int j=0;
        for(int i=2;i<=len;++i){
            while(j&&s[j+1]!=s[i]) j=fail[j];
            if( s[j+1]== s[i])j++;
            fail[i]=j;
        }
        // for(int lenp=1;lenp<=len;lenp++){
        //     int pre=0;
        //     int k=0;
        //     for(int i=lenp+1;i<=len;i++){
        //         while(k&&s[k+1]!=s[i])k=fail[k];
        //         if(s[k+1]==s[i])k++;
        //         if(k==lenp){
        //             if(pre+lenp<=i){
        //                 pre=i;
        //                 cnt++;
        //                 if(cnt==10007)cnt=0;
        //             }
        //             k=fail[k];
        //         }
        //     }
        // }
        int ans=len%10007;
        for(int i=1;i<=len;++i){
            ans=(ans+(fail[i]==0?0:1))%10007;
        }
        cout<<ans<<endl;
    }
    return 0;
}
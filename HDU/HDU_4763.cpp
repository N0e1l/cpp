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
    int n;
    cin>>n;
    while(n--){
        fail[0]=fail[1]=0;
        cin>>s+1;
        int j=0;
        int lenS=strlen(s+1);
        for(int i=2;i<=lenS;i++){
            while(j&&s[j+1]!=s[i]) j=fail[j];
            if(s[j+1]==s[i])++j;
            fail[i]=j;
        }
        int bd=fail[lenS];
        if(bd==0){cout<<"0"<<endl;continue;}
        int f=0;
        for(int len=bd;len>=0;len--){
            if(len*3>lenS)continue;
            //1~len为待查；被查获片段: (len+1,lenS-len-1)
            int k=0;
            for(int i=len+1;i<=lenS-len;++i){
                while(k&&s[k+1]!=s[i])k=fail[k];
                if(s[k+1]==s[i])k++;
                if(k==len){cout<<len<<endl;f=1;break;}
            }
            if(f)break;
        }
    }
    return 0;
}
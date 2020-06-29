#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

const int N=1000000+10;
int fail[N],Pos[N],cnt;
char str[N],p[N];


void get_fail(){
    int lens=strlen(str+1);
    int lenp=strlen(p+1);
    for(int i=2,j=0;i<=lenp;i++){
        while(j&&p[j+1]!=p[i])j=fail[j];
        if(p[j+1]==p[i])++j;
        fail[i]=j;
    }
}

void KMP(){
    get_fail();
    int lens=strlen(str+1);
    int lenp=strlen(p+1);
    for(int i=1,j=0;i<=lens;i++){
        while(j&&p[j+1]!=str[i])j=fail[j];
        if(p[j+1]=str[i])++j;
        if(j==lenp){Pos[cnt++]=i-lenp+1;j=fail[j];}
    }
}

int main()
{
    cin>>str+1>>p+1;
    KMP();
    for(int i=0;i<cnt;i++)cout<<Pos[i]<<endl;
    int len=strlen(p+1);
    for(int i=1;i<=len;i++)cout<<fail[i]<<" ";
    return 0;
}
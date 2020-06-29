#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

double f(double x,double n){
    double sum=0;
    for(int i=1;i<=n;i++){
        sum+=double(i);
    }
    double re=sum/double(n);
    //cout<<re*x<<endl;
    return double(re*x);
}


int main()
{
    string s;
    cin>>s;
    int len=s.length();
    double xx=0,nn=0,num=0;
    bool bfD=false;
    double ans=0.0;
    for(int i=0;i<len;++i){
        if(s[i]=='d'){
            bfD=1;
            xx=num;
            num=0;
        }
        if(s[i]<='9'&&s[i]>='0'){
            num=num*10+s[i]-'0';
        }
        if(s[i]=='+'){
            if(bfD){
                nn=num;
               // cout<<xx<<" "<<nn<<endl;
                ans+=f(xx,nn);
                //cout<<ans<<" ";
                bfD=0;num=0;
            }
            else {ans+=num;num=0;}
        }
    }
    if(bfD){ans+=f(xx,num);}
    else ans+=num;
    int tmp=ans;
    if(ans==tmp){
        printf("%d",tmp);
    }
    else printf("%.1f",ans);
    return 0;
}
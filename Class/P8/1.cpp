#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,num[201314];
int main()
{
    int t;
    cin>>t;
    for(int ji=1; ji<=t; ji++)
    {
        memset(num,0,sizeof(num));
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>num[i];
        int beg=1,end=1,sum=0,ans=-5201314,te=1;
        for(int i=1; i<=n; i++)
        {
            if(sum>=0)
                sum+=num[i];
            else
            {
                sum=num[i];
                te=i;
            }
            if(sum>ans)
            {
                ans=sum;
                beg=te;
                end=i;
            }
        }
        cout<<"Case "<<ji<<":\n";
        cout<<ans<<" "<<beg<<" "<<end<<endl;
        if(ji!=t)
            cout<<endl;
    }
    return 0;
}
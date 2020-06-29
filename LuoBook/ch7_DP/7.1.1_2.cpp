//P118 7.1.1
//!�������:��n��Ӳ��,�������ޣ����ڸ����Ľ�������ٵ�Ӳ�Ҵճ����������Ӳ�����������
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

const int Max=305;
int type[5]={1,5,10,25,50};
int dp[Max];
//! �ؼ���,��¼Ӳ����ϣ�����dp��������ʣ���������dp_path��¼·��
//!dp_path[i]=m; �ճ�iԪǮ�����ŷ��������һöӲ�ҵ�����.�������ϸ�ڼ�����pr(t);
int dp_path[Max];

void solve(){
    for(int i=1;i<=Max;i++){
        dp[i]=0x3f3f3f3f;
    }
    dp[0]=0;
    for(int i=0;i<=4;i++){   //����ת��
        for(int j=type[i];j<=Max;j++){
            if(dp[j]>dp[j-type[i]]+1){
                dp_path[j]=type[i];
                dp[j]=dp[j-type[i]]+1;
            }
        }
    }
}
void pr(int t){
    cout<<dp[t]<<endl;
    //! �������:
    while(t){  //t��Ϊ0ʱ�����������
        cout<<dp_path[t]<<" ";//��ǰӵ��tԪ,���ŷ��������һöӲ��Ϊdp_path[t];
        t-=dp_path[t];//��ǰ������
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    solve();
    while(n--){
        int ask;
        cin>>ask;
        pr(ask);
    }
    return 0;
}
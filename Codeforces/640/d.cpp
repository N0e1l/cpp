#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int a[1010];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int A=1,B=n,M_A=0,M_B=0,cnt=0;
        int P_A=-1,P_B=-1;//Ç°Ò»ÂÖÌÇ¹û
        while(1){
            //Alice:
            int sumA=0;
            while(1){
                sumA+=a[A++];
                if(sumA>P_B||A>B)break;
            }
            P_A=sumA;M_A+=sumA;
            cnt++;
            if(A>B)break;
            int sumB=0;
            while(1){
                sumB+=a[B--];
                if(sumB>P_A||A>B)break;
            }
            P_B=sumB;M_B+=sumB;
            cnt++;
            if(A>B)break;
        }
        cout<<cnt<<" "<<M_A<<" "<<M_B<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
inline int lowbit(int x){
    return x&(-x);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        if(num>2&&num%4==0){
            printf("YES\n");
            for(int i=1;i<=num/2;i++){
                printf("%d ",2*i);
            }
            for(int i=1;i<=num/2-1;i++){
                printf("%d ",2*i-1);
            }
            printf("%d\n",3*num/2-1);
        }
        else printf("NO\n");
    }
    return 0;
}
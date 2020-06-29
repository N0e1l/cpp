//Absolute Game

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int a[1010],b[1010];
int vira[1010],virb[1010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int T=n-1;
    while(T--){
        int Min=101010101,tmp=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(vira[i]||virb[j])continue;
                if(abs(a[i]-b[j])<Min) tmp=i;
            }
        }
        vira[tmp]=1;
        int tmp2=1,Max=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j--){
                if(vira[i]||virb[j])continue;
                if(abs(a[i]-b[j])>Max) tmp2=j;
            }
        }
        virb[tmp2]=1;
    }
    int aa=1,bb=1;
    while(vira[aa++]);
    while(virb[bb++]);
    cout<<abs(a[aa]-b[bb]);
    return 0;
}
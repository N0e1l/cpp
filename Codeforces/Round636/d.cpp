using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
const int Ma=2e5+100;
int eq[2*Ma],cover[2*Ma],a[Ma];

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        memset(eq,0,sizeof(eq));
        memset(cover,0,sizeof(cover));
        for(int i=1;i<=n/2;++i){
            ++eq[a[i]+a[n-i+1]];
            ++cover[min(a[i],a[n-i+1])+1];
            --cover[max(a[i],a[n-i+1])+k+1];
        }
        for(int i=2;i<=2*k;++i){
            cover[i]+=cover[i-1];
        }
        int ans=0x3f3f3f;
        for(int i=2;i<=2*k;++i){
            ans=min(ans,cover[i]-eq[i]+(n/2-cover[i])*2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
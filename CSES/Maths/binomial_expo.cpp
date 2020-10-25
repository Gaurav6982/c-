#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll power(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            ans=(ans*a)%mod;
            b--;
        }
        else
        {
            a=(a*a)%mod;
            b/=2;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll fac[1000001];
    fac[0]=fac[1]=1;
    for(int i=2;i<1000001;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    // rep(i,10) cout<<fac[i]<<endl;
    ll n;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        ll po=fac[a];
        // cout<<po<<endl;
        po=(po*power(fac[b],mod-2))%mod;
        // cout<<po<<endl;
        po=(po*power(fac[a-b],mod-2))%mod;
        cout<<po<<endl;
    }
    return 0;
}
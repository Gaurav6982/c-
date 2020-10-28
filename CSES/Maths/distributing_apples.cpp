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
    ll n,m;
    ll fact[2000005];
    fact[0]=fact[1]=1;
    for(int i=2;i<2000005;i++)
    fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    cin>>n>>m;
    ll ans=fact[n+m-1];
    ans=((ans%mod)*power(fact[n-1],mod-2)%mod)%mod;
    ans=((ans%mod)*power(fact[m],mod-2)%mod)%mod;
    cout<<ans;
    return 0;
}
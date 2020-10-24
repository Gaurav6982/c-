#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)

using namespace std;
ll dp[1000001];
ll find(ll arr[],ll n,ll x)
{
    if(x==0)
    return 1;
    if(n==0)
    return 0;
    if(dp[x]!=-1)
    return dp[x];
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]<=x)
        {
            ans+=find(arr,n,x-arr[i])%mod;
        }
        else
        {
            break;
        }
    }
    return dp[x]=ans%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x;
    cin>>n>>x;
    ll arr[n];
    rep(i,n) cin>>arr[i];
    sort(arr,arr+n);
    rep(i,1000001) dp[i]=-1;
    cout<<find(arr,n,x);
}
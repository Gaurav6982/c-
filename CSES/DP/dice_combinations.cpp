#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll dp[1000001];
ll find(ll sum)
{
    if(sum==0)
    return 1;
    if(sum<0)
    return 0;
    if(dp[sum]!=-1)
    return dp[sum];
    ll ans=0;
    for(int i=1;i<=6;i++)
    {
        if(i<=sum)
        ans+=find(sum-i)%mod;
    }
    return dp[sum]=ans%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll sum;
    cin>>sum;
    // int arr[]={1,2,3,4,5,6};
    rep(i,1000001) dp[i]=-1;
    cout<<find(sum);
}
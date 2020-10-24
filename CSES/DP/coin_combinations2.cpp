#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)

using namespace std;
ll dp[101][1000001];
ll find(int arr[],int n,int x)
{
    if(x==0)
    return 1;
    if(n==0)
    return 0;
    if(dp[n][x]!=-1)
    return dp[n][x];
    ll ans=0;
    if(arr[n-1]<=x)
    ans=(find(arr,n-1,x)%mod)+(find(arr,n,x-arr[n-1])%mod);
    else
    ans=find(arr,n-1,x)%mod;
    return dp[n][x]=ans%mod;
    // return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    int arr[n];
    rep(i,n) cin>>arr[i];
    // sort(arr,arr+n);
    rep(i,101) {rep(j,1000001) dp[i][j]=-1;}
    cout<<find(arr,n,x)<<endl;
    return 0;
}
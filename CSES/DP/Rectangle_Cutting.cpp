#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int dp[505][505];
int find(int n,int m)
{
    if(n==m)
    return 0;
    if(n==1 || m==1)
    return max(n,m)-1;
    int ans=INT_MAX;
    if(dp[n][m]!=-1)
    return dp[n][m];
    for(int i=1;i<=n/2;i++)
    {
        ans=min(ans,find(n-i,m)+find(i,m));
    }
    for(int i=1;i<=m/2;i++)
    {
        ans=min(ans,find(n,m-i)+find(n,i));
    }
    return dp[n][m]=1+ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    rep(i,n+1) rep(j,m+1) dp[i][j]=-1;
    cout<<find(n,m);
    return 0;
}
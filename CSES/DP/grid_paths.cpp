#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int dp[1001][1001];
int find(string grid[],int n,int i,int j)
{
    if(i==n-1 && j==n-1)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    if(i+1<n && grid[i+1][j]!='*')
    ans+=find(grid,n,i+1,j)%mod;
    if(j+1<n && grid[i][j+1]!='*')
    ans+=find(grid,n,i,j+1)%mod;
    return dp[i][j]=ans%mod;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
   string grid[n];
    rep(i,n) cin>>grid[i];
    rep(i,n) rep(j,n) dp[i][j]=-1;
    if(grid[n-1][n-1]!='*' && grid[0][0]!='*')
    cout<<find(grid,n,0,0);
    else
    cout<<0;
    return 0;
}
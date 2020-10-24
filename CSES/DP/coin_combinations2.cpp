#include<bits/stdc++.h>
 
#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    vector<int> arr(n);
    cin>>n>>x;
    rep(i,n) cin>>arr[i];
 
    int dp[n+1][x+1];
    rep(i,n+1) dp[i][0]=1;
    rep(i,x+1) dp[0][i]=0;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<x+1;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i-1]])%mod;
            else
            dp[i][j]=dp[i-1][j]%mod;
        }
    }
    cout<<dp[n][x];
 
}
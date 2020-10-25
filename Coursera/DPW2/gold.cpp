#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int dp[301][10001];
int find(int arr[],int w,int n)
{
    if(w==0 || n==0)
    return 0;
    if(dp[n][w]!=-1)
    return dp[n][w];
    int ans=0;
    if(arr[n-1]<=w)
    ans= max(arr[n-1]+find(arr,w-arr[n-1],n-1),find(arr,w,n-1));
    else
    {
        ans= find(arr,w,n-1);
    }
    return dp[n][w]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w,n;
    cin>>w>>n;
    int arr[n];
    rep(i,n) cin>>arr[i];
    rep(i,n+1) rep(j,w+1) dp[i][j]=-1;
    cout<<find(arr,w,n);
}
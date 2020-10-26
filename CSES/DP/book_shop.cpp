#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int find(int n,int price[],int pages[],int x)
{
    int dp[n+1][x+1];

    for(int i=0;i<n+1;i++)
    dp[i][0]=0;
    for(int i=0;i<x+1;i++)
    dp[0][i]=0;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<x+1;j++)
        {
            if(price[i-1]<=j)
            dp[i][j]=max(dp[i-1][j],pages[i-1]+dp[i-1][j-price[i-1]]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][x];
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    int pages[n];
    int price[n];
    rep(i,n) cin>>price[i];
    rep(i,n) cin>>pages[i];
   
    cout<<find(n,price,pages,x);
    return 0;
}
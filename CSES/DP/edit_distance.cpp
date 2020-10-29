#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    int n,m;
    n=a.size();
    m=b.size();
    int dp[n+1][m+1];
    dp[0][0]=0;
    for(int i=1;i<n+1;i++)
    dp[i][0]=i;
    for(int i=1;i<m+1;i++)
    dp[0][i]=i;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    cout<<dp[n][m];
    
    return 0;
}
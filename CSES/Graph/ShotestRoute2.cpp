#include<bits/stdc++.h>

#define ll long long
#define MAX_VAL 1e17
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void floyd(int n,int m,vector<ll> dp[])
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            for(int k=0;k<n+1;k++)
            {
                if(dp[j][i]<MAX_VAL && dp[i][k]<MAX_VAL)
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<ll> dp[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=vector<ll>(n+1,MAX_VAL);
        dp[i][i]=0;
    }
    while(m--)
    {
        ll a,b;
        ll c;
        cin>>a>>b>>c;
        if(c<dp[a][b])
        dp[a][b]=c;
        if(c<dp[b][a])
        dp[b][a]=c;   
    }
    
    floyd(n,m,dp);
    while(q--)
    {
        int a ,b;

        cin>>a>>b;
        if(dp[a][b]!=MAX_VAL)
        cout<<dp[a][b]<<endl;
        else 
        cout<<-1<<endl;
    }
    return 0;
}
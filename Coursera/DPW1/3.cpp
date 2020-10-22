#include<bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int dp[105][105];
int find(string a,string b,int i,int j)
{
    if(i<0 && j<0)
    return 0;
    if(i<0 || j<0)
    return max(i+1,j+1);
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    if(a[i]==b[j])
    ans=find(a,b,i-1,j-1);
    else
    {
        ans=1+min(find(a,b,i-1,j),min(find(a,b,i,j-1),find(a,b,i-1,j-1)));
    }
    return dp[i][j]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    rep(i,105) rep(j,105) dp[i][j]=-1;
    cout<<find(a,b,a.size()-1,b.size()-1);
}
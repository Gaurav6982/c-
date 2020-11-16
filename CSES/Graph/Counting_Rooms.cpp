#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void dfs( vector<vector<char> >&grid ,int i,int j,int n,int m)
{
    if(i<0 || i>=n ||j<0||j>=m ||grid[i][j]=='#'||grid[i][j]=='+')
    return;

    grid[i][j]='+';

    dfs(grid,i+1,j,n,m);
    dfs(grid,i-1,j,n,m);
    dfs(grid,i,j+1,n,m);
    dfs(grid,i,j-1,n,m);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char> > grid(n);
    rep(i,n)
    {
    // grid[i].push_back(0);
    grid[i]=vector<char>(m);
    rep(j,m)
    cin>>grid[i][j];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='.')
            {
                dfs(grid,i,j,n,m);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
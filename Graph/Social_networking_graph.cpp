#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<=n;i++)

using namespace std;
vector<int> adj[1000001];
int visited[1000001];
int ans=0;
void dfs(int a,int dist,int b)
{
    visited[a]=1;
    if(dist==b)
    ans++;
    for(int i=0;i<adj[a].size();i++)
    {
        int child=adj[a][i];
        if(visited[child]==0)
        {
            dfs(child,dist+1,b);
        }

    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    int m;
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        rep(i,n) visited[i]=0;
        ans=0;
        dfs(a,0,b);
        cout<<ans<<endl;
    }
    
    return 0;
}
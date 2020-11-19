#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<vector<int> > adj(10001,vector<int>());
int visited[10001];
int ans=INT_MIN;
int final_node=-1;
void dfs(int node,int distance)
{
    visited[node]=1;
    if(distance>ans)
    {
        ans=distance;
        final_node=node;
    }
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        dfs(adj[node][i],distance+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    // for(int i=0;i<=n;i++) adj[i].clear();
    for(int i=0;i<=n;i++) visited[i]=0;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    // cout<<ans;
    ans=INT_MIN;
    for(int i=0;i<=n;i++) 
    visited[i]=0;
    // cout<<final_node;
    dfs(final_node,0);
    cout<<ans;
    return 0;
}
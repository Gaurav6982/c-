#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[100001];
vector<bool> visited;
vector<int> in,low;
int timer;
vector<int> points;
void dfs(int node,int parent)
{
    visited[node]=true;
    in[node]=low[node]=timer++;
    int children=0;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(child==parent) continue;
        if(visited[child])
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node] && parent!=-1)
            {
                points.push_back(node);
            }
            children++;
        }
        
    }
    if(parent==-1 && children>1)
    points.push_back(node);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    timer=0;
    visited.assign(n+1, false);
    in.assign(n+1, -1);
    low.assign(n+1, -1);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs (i,-1);
    }
    cout<<points.size()<<endl;
    rep(i,points.size()) cout<<points[i]<<" ";

    return 0;
}
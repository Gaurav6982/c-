#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[10001];
bool visited[10001];
int in[10001],low[10001];
int timer;
// int ans;
set<int> AP;
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
        low[node]=min(low[node],in[child]);
        else
        {
             dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node] && parent!=-1)
            AP.insert(node);
            children++;
        }
        
    }
    if(parent==-1 && children>1)
    AP.insert(node);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
        break;
        timer=0;
        AP.clear();
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            visited[i]=false;
            in[i]=low[i]=-1;
        }
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,-1);
        cout<<AP.size()<<endl;

    }
    return 0;
}
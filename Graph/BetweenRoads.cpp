#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[100001];
int visited[100001];
int low[100001];
int in[100001];
int timer;
bool has_bridge=false;
void dfs(int node,int parent)
{
    visited[node]=1;
    low[node]=in[node]=timer;
    timer++;

    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(child==parent) continue;
        if(visited[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);

            if(low[child]>=in[node])
                has_bridge=true;

            low[node]=min(low[node],low[child]);
        }
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    dfs(1,0);
    if(has_bridge==true)
    cout<<0;
    else
    {
        cout<<"YES"<<endl;
    }
    
    return 0;
}
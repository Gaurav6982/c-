#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[100001];
bool visited[100001];
int parents[100001];
int last=-1;
int first=-1;
bool dfs(int node,int parent){
    visited[node]=true;
    parents[node]=parent;

    // bool ret=false;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(child==parent) continue;
        if(visited[child])
        {
            first=child;
            last=node;
            return true;
        }
        else
        {
            
            if(dfs(child,node))return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    rep(i,n+1) {visited[i]=false;parents[i]=-1;}
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        if(dfs(i,-1)) break;
    }
    if(last==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<int> ans;
        ans.push_back(first);
        while(last!=first)
        {
            ans.push_back(last);
            last=parents[last];
        }
        ans.push_back(last);
        cout<<ans.size()<<endl;
        rep(i,ans.size()) cout<<ans[i]<<" ";

    }
    
    return 0;
}
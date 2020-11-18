#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
bool dfs(vector<int>& colors,vector<vector<int> >& adj,int node,int c,vector<bool>& visited)
{
    visited[node]=true;
    colors[node]=c;

    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            if(!dfs(colors,adj,adj[node][i],c^1,visited))return false;
        }
        else
        {
            if(colors[node]==colors[adj[node][i]])
            return false;
        }
    }
    return true;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n+1,vector<int>());
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> colors(n+1,-1);
    vector<bool> visited(n+1,false);
    bool possible=true;
    for(int i=1;i<n+1;i++)
    {
        if(!visited[i]&&!dfs(colors,adj,i,0,visited))
        {
            possible=false;
        }
    }
    if(possible)
    {
        for(int i=1;i<n+1;i++)
        cout<<colors[i]+1<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
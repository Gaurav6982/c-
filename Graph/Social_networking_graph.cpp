#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<=n;i++)

using namespace std;
vector<int> adj[1000001];
int visited[1000001]={0};
int dist[1000001]={0};
int levels[1000001]={0};
void bfs(int a,int b)
{
    queue<int> q;
    q.push(a);
    visited[a]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++)
        {
            int child=adj[node][i];
            if(visited[child]==0)
            {
                visited[child]=1;
                dist[child]=dist[node]+1;
                levels[dist[child]]++;
                q.push(child);
            }
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
        rep(i,n) visited[i]=0,levels[i]=0,dist[i]=0;
        bfs(a,b);
        cout<<levels[b]<<endl;
    }
    
    return 0;
}
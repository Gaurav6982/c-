#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[10001];
int visited[10001];
void bfs(int node,vector<int>& dist)
{
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        for(int i=0;i<adj[n].size();i++)
        {
            if(!visited[adj[n][i]])
            {
                visited[adj[n][i]]=1;
                if(dist[n]+1<dist[adj[n][i]])
                dist[adj[n][i]]=dist[n]+1;  
                q.push(adj[n][i]);         
            }
        }   
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) visited[i]=0;
        for(int i=1;i<=n;i++) adj[i].clear();

        while(m--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;

        bfs(1,dist);
        cout<<dist[n]<<endl;

    }
    return 0;
}
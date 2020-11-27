#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define iPair pair<ll,int>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<pair<int,ll> > adj[2505];
vector<int> trans[2505];
int visited[2505];
ll dist[2505];

bool dfs(int node,int n,vector<bool>& vis)
{
    vis[node]=true;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i].first;
        if(!vis[child])
        {
            if(child==n)
            return true;
            if(dfs(child,n,vis)) return true;
        }   
    }
    return false;
}
bool detectCycle(int node,int parent,int n)
{
    visited[node]=true;
        for(int i=0;i<adj[node].size();i++)
        {
            int child=adj[node][i].first;
            if(!visited[child])
            {
                if(detectCycle(child,node,n)) return true;
            }
            else
            {
                if(child!=parent)
                {
                    vector<bool> vis(n+1,false);
                    if(dfs(child,n,vis)) return true;
                }
            }
            
        }
    return false;   
}
int in[2505];
int timer;
vector<int> topo;
void topoS(int n){
    queue<int> q;
    for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
    while(!q.empty())
    {
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for(int i=0;i<adj[node].size();i++)
        {
            int child=adj[node][i].first;
            in[child]--;
            if(in[child]==0)
            q.push(child);

        }
    }
}
void djikstra(int n)
{
    // priority_queue<iPair,vector<iPair>,greater<iPair> > q;
    // q.push(make_pair(0,1));
    dist[1]=0;
    // while(!q.empty())
    for(int i=0;i<topo.size();i++)
    {
        // int node=q.top().second;
        int node=topo[i];
        // q.pop();
        if(!visited[node])
        {

        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            int child=adj[node][i].first;
            ll w=adj[node][i].second;
            if(!visited[child])
            {
                if(dist[node]+w<dist[child])
                dist[child]=w+dist[node];
                // q.push(make_pair(dist[child],child));
                
            }
        }
        }

    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        ll x;
        cin>>a>>b>>x;
        x=-x;
        adj[a].push_back(make_pair(b,x));
        trans[b].push_back(a);
        in[b]++;
    }
    if(detectCycle(1,-1,n))
    {
        cout<<-1<<endl;
    }
    else
    {

        for(int i=1;i<=n;i++) visited[i]=0,dist[i]=LONG_MAX;
        // for(int i=1;i<=n;i++) cout<<in[i]<<" ";
        topoS(n);
        // rep(i,topo.size()) cout<<topo[i]<<" ";cout<<endl;
        djikstra(n);
        cout<<-dist[n]<<endl;
    }
    
    return 0;
}
// dist[child]==INT_MAX || 
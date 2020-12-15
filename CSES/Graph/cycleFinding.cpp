#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define INF 1e14
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[2501];
ll dist[2501];
int parent[2501];
vector<pair<ll,pair<int,int> > > e;
int p;
bool bellman(int n,int m)
{
    // int x;
    for(int i=0;i<n;i++)
    {
        p=-1;
        for(int j=0;j<m;j++)
        {
            ll cost=e[j].first;
            int u=e[j].second.first;
            int v=e[j].second.second;

            if(dist[u]<(long long)INF)
            {
                if(dist[v]>dist[u]+cost)
                {
                    dist[v]=max((long long)(-INF),dist[u]+cost);
                    parent[v]=u;
                    p=u;
                }
            }
        }
    }
    // cout<<x<<endl;
    if(p!=-1)
    return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        ll x;
        cin>>a>>b>>x;
        a--;
        b--;
        adj[a].push_back(b);
        e.push_back(make_pair(x,make_pair(a,b)));
    }
    rep(i,n) parent[i]=i;
    bool b=bellman(n,m);
    vector<int> path;
    if(b)
    {
        cout<<"YES"<<endl;
        int y = p;

        // to trace back to such a vertex included in a negtative cycle.
        for (int i=0; i<n; ++i)
            y = parent[y];

        vector<int> path;
        for (int cur=y; ; cur=parent[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());
        rep(i,n) cout<<path[i]+1<<" ";
        if(path[n-1]!=path[0])
        cout<<path[0]+1;
        cout<<endl;
        // rep(i,n) cout<<parent[i]<<" ";cout<<endl;
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}
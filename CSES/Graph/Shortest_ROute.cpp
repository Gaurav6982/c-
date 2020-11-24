#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<pair<ll,ll> > adj[100001];
ll visited[100001];
// int dist[100001];
ll find_min(ll dist[],ll n)
{
    ll min_vertex=-1;
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(min_vertex==-1)
            min_vertex=i;
            else if(dist[i]<dist[min_vertex])
            min_vertex=i;
        }
    }
    return min_vertex;
}
void find(ll dist[],ll n)
{
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >, greater<pair<ll,ll> > > q;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        ll min_vertex=q.top().second;
        // int weight=q.top().first;
        q.pop();
        if(!visited[min_vertex]){
            visited[min_vertex]=1;
        for(int j=0;j<adj[min_vertex].size();j++)
        {
            pair<ll,ll> child=adj[min_vertex][j];
            
            if(!visited[child.first])
            {
                if(dist[min_vertex]+child.second<dist[child.first])
                dist[child.first]=dist[min_vertex]+child.second;
                q.push(make_pair(dist[child.first],child.first));
            }
        }}
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
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        // adj[b].push_back(make_pair(a,w));
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<"-> ";
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<") ,";
    //     }
    //     cout<<endl;
    // }
    ll dist[n+1];
    for(int i=2;i<=n;i++) dist[i]=LONG_MAX;
    dist[1]=0;
    find(dist,n);
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";

    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<pair<int,ll> > adj[100001];
vector<vector<ll> > dist;
void find(int n,int k)
{
    priority_queue<pair<ll,int> ,vector<pair<ll,int> > , greater<pair<ll,int> > > pq;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        // cout<<"here"<<endl;
        ll weight=pq.top().first;
        int v=pq.top().second;
        // cout<<v<<endl;
        pq.pop();
        if(dist[v][k-1]<weight) continue;

        for(int i=0;i<adj[v].size();i++)
        {
            int u=adj[v][i].first;
            ll c=adj[v][i].second;
            if(weight+c<dist[u][k-1])
            {
                dist[u][k-1]=weight+c;
                pq.push(make_pair(dist[u][k-1],u));
                sort(dist[u].begin(),dist[u].end());
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++)
    {
        dist.push_back( vector<ll>(k,LONG_MAX));
    }
    // for(int i=0;i<k;i++)
    // {
    //     dist[1][i]=0;
    // }
    while(m--)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
    }
    // cout<<"wd"<<endl;
    find(n,k);
    // cout<<"done"<<endl;
    for(int i=0;i<dist[n].size();i++)
    {
        cout<<dist[n][i]<<" ";
    }
    return 0;
}
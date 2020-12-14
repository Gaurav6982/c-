#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1e16
#define NINF -1*INF
using namespace std;
vector<pair<ll,pair<int,int> > > e;
ll dist[2501];
int xl;
void bellman(int n,int m){
    for(int i=0;i<n-1;i++)
    {   
        for(int j=0;j<m;j++)
        {
            int u=e[j].second.first;
            int v=e[j].second.second;
            ll cost=e[j].first;
            // cout<<u<<" "<<v<<" "<<cost;
            if(dist[u]<(long long)INF)
            if(dist[v]>dist[u]+cost)
            {
                dist[v]=max((long long)(NINF),dist[u]+cost);
            }
        }
    }
    // cout<<"x: "<<xl<<endl;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
             int u=e[j].second.first;
            int v=e[j].second.second;
            ll cost=e[j].first;
            if(dist[u]<(long long)INF)
            {
                dist[v]=max((long long)(NINF),dist[v]);
                if(dist[u]+cost<dist[v])
                dist[v]=NINF;
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
    // cout<<n<<m;
    int a,b;
    ll x;
    rep(i,m)
    {
        cin>>a>>b>>x;
        a--;
        b--;
        e.push_back(make_pair(-x,make_pair(a,b)));
    }
    rep(i,n) dist[i]=INF;
    dist[0]=0;
    bellman(n,m);
    // rep(i,n) cout<<dist[i];
    if(dist[n-1]==NINF)
    cout<<-1;
    else
    cout<<-dist[n-1];
    return 0;
}
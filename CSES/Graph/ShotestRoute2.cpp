#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<pair<int,ll> > adj[100001];
struct edges{
    int from;
    int to;
    ll weight;
};
ll dist[100001];
void bellman(int n,int m,vector<edges>& edgelist)
{
    for(int i=0;i<n-1;i++)
    {
        for(int i=0;i<edgelist.size();i++)
        {
            int a=edgelist[i].from;
            int b=edgelist[i].to;
            int w=edgelist[i].weight;
            if(dist[a]==LONG_MAX) continue;
            if(dist[a]+w<dist[b])
            dist[b]=dist[a]+w;
            
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    rep(i,n+1) dist[i]=LONG_MAX;
    dist[0]=dist[1]=0;
    vector<edges> edgelist;
    while(m--)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        edges temp;
        temp.from=a;
        temp.to=b;
        temp.weight=c;
        edgelist.push_back(temp);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    bellman(n,m,edgelist);
    while(q--)
    {
        int a ,b;

        cin>>a>>b;
        if(a<b) swap(a,b);
        if(dist[a]==LONG_MAX||dist[b]==LONG_MAX)
        cout<<-1<<endl;
        else
        {
            cout<<dist[a]-dist[b]<<endl;
        }
        
    }
    return 0;
}
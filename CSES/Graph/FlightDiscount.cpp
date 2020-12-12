#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<pair<int,ll> > adj[100001];
ll dist[100001];
ll dis[100001];
bool visited[100001];
// int parents[100001]={-1};
void djikstras()
{
    priority_queue<pair<ll,pair<int,int> >, vector<pair<ll,pair<int,int> > > , greater<pair<ll,pair<int,int> > > > q; //weight,node,coupon applied or not
    q.push(make_pair(0,make_pair(1,0)));
    while(!q.empty())
    {
        int min_vertex=q.top().second.first;
        ll cost=q.top().first;
        int coupon=q.top().second.second;
        q.pop();

        visited[min_vertex]=true;
            for(int i=0;i<adj[min_vertex].size();i++)
            {
                int child=adj[min_vertex][i].first;
                if(visited[child]) continue;
                    ll weight=adj[min_vertex][i].second;
                        // parents[child]=min_vertex;
                    if(coupon==1)
                    {
                        if(dis[min_vertex]+weight<dis[child])
                        dis[child]=dis[min_vertex]+weight;
                        q.push(make_pair(dis[child],make_pair(child,1)));
                    }
                    else
                    {
                        dist[child]=min(dist[child],dist[min_vertex]+weight);
                        q.push(make_pair(dist[child],make_pair(child,0)));
                        dis[child]=min(dis[child],min(dis[min_vertex]+weight,dist[min_vertex]+weight/2));
                        q.push(make_pair(dis[child],make_pair(child,1)));
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
    int a,b;
    ll c;
    for(int i=0;i<n+1;i++) dist[i]=LONG_MAX,dis[i]=LONG_MAX,visited[i]=false;
    dist[1]=0;
    dis[1]=0;
    while(m--)
    {
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        // adj[b].push_back(make_pair(a,c));
    }
    djikstras();
    // ll max_val=0;
    // // int i=n;
    // int i=n;
    // while(true)
    // {
    //     if(i==0)
    //     break;
    //     int first_v=i;
    //     int second_v=parents[i];
    //     ll w=dist[first_v]-dist[second_v];
    //     max_val=max(max_val,w);
    //     i=parents[i];
    // }
    // cout<<"PARENTS ARRAY"<<endl;
    // for(int i=1;i<=n;i++)
    // cout<<parents[i]<<" ";
    // cout<<"\DIST ARRAY"<<endl;
    // for(int i=1;i<=n;i++)
    // cout<<dist[i]<<" ";
    // cout<<endl;
    cout<<min(dist[n],dis[n])<<endl;
    // cout<<max_val<<endl;
    // cout<<dist[n]-max_val+floor(max_val/2)<<endl;
    return 0;
}
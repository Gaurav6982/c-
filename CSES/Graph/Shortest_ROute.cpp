#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<pair<int,int> > adj[100001];
int visited[100001];
// int dist[100001];
int find_min(int dist[],int n)
{
    int min_vertex=-1;
    for(int i=1;i<=n;i++)
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
void find(int dist[],int n)
{
    for(int i=1;i<=n;i++)
    {
        int min_vertex=find_min(dist,n);
        if(!visited[min_vertex]){
            visited[min_vertex]=1;
        for(int j=0;j<adj[min_vertex].size();j++)
        {
            pair<int,int> child=adj[min_vertex][j];
            
            if(!visited[child.first])
            {
                if(dist[min_vertex]+child.second<dist[child.first])
                dist[child.first]=dist[min_vertex]+child.second;
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
    int dist[n+1];
    for(int i=2;i<=n;i++) dist[i]=INT_MAX;
    dist[1]=0;
    find(dist,n);
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";

    return 0;
}
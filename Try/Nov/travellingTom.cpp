#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
struct edge{
    int u,v,l;
    vector<int> ls;
    int w;
};
bool comp(edge a,edge b)
{
    return a.w<b.w;
}
int parent[100001];
int rnk[100001];
int find(int a){
    if(parent[a]==a)
    return a;
    return parent[a]=find(parent[a]);
}
void join(int a,int b){
    if(rnk[a]<rnk[b])
    swap(a,b);
    parent[b]=a;
    if(rnk[a]==rnk[b])
    rnk[a]++;
}
int num_edges=0;
void kruskal(edge edges[],int m,int cost[],int k,int needed[]){
    
    for (int i = 0; i < m; i++)
    {
        int u=edges[i].u-1;
        int v=edges[i].v-1;
        int w=edges[i].w;
        if(find(u)!=find(v))
        {
            num_edges++;
            join(u,v);
            needed[u]=needed[v]=1;        
        }
    }
    
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int cost[k];
    for(int i=0;i<k;i++) cin>>cost[i];
    edge edges[m];
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].u;
        cin>>edges[i].v;
        cin>>edges[i].l;
        int weight=0;
        for(int j=0;j<edges[i].l;j++)
        {
            int temp;
            cin>>temp;
            edges[i].ls.push_back(temp);
            weight+=cost[temp-1];
        }
        edges[i].w=weight;
    }
    sort(edges,edges+m,comp);
    int needed[k];
    rep(i,k) needed[i]=0;
    rep(i,n+1) parent[i]=i,rnk[i]=0;
    kruskal(edges,m,cost,k,needed);
    int ans=0;
    for (int i = 0; i < k; i++)
    {
        // cout<<needed[i]<<" ";
        if(needed[i]==1)
            ans+=cost[i];
    }
    if(num_edges==n-1)
    cout<<ans<<endl;
    else
    {
        cout<<1<<endl;
    }
    
    // for(int i=0;i<m;i++)
    // {
    //     cout<<"Edge "<<i+1<<" : "<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
    // }
    return 0; 
}
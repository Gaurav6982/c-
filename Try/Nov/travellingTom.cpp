#include<bits/stdc++.h>
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
    for(int i=0;i<m;i++)
    {
        cout<<"Edge "<<i+1<<" : "<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
    }
    return 0; 
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
pair<int,pair<int,int> >  edges[10000];
struct edge{
    int a,b,w;
};
int parents[100001];
// bool comp(pair<int,int> a,pair<int,int> b)
// {
//     if(a.second<b.second)
//     return true;
//     return false;
// }
int find(int a)
{
    if(parents[a]==-1) return a;
    return find(parents[a]);
}
void join(int a,int b)
{
    parents[a]=b;
}
int kruskal(int n,int m){
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int a=edges[i].second.first;
        int b=edges[i].second.second;
        int w=edges[i].first;
        if(find(a)!=find(b))
        {
            join(a,b);
            ans+=w;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) parents[i]=-1;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]=(make_pair(w,make_pair(a,b)));
        // adj[a].push_back(make_pair(a,w));
    }
    sort(edges,edges+m);
    int minimumCost = kruskal(n,m);
    cout << minimumCost << endl;
    return 0;
}
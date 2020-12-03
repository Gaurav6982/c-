#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
pair<int,pair<int,int> >  edges[1000001];
int parents[1000001];
int find(int a)
{
    if(parents[a]==-1) return a;
    return parents[a]=find(parents[a]);
}
void join(int a,int b)
{
    parents[a]=b;
}
int edge=0;
int kruskal(int n,int m,ll k){
    ll ans=0;
    int transformations=0;
    for(int i=0;i<m;i++)
    {
        int a=edges[i].second.first;
        int b=edges[i].second.second;
        int w=edges[i].first;
        
            if(find(a)!=find(b))
            {
                join(a,b); edge++;
                if(ans+w<=k)
                ans+=w;
                else
                transformations++,ans++;
            }
    }
    return transformations;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    ll k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) parents[i]=-1;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]=(make_pair(w,make_pair(a,b)));
        // adj[a].push_back(make_pair(a,w));
    }
    sort(edges,edges+m);
    int minimumTransformation = kruskal(n,m,k);
    if(edge==n-1)
    cout << minimumTransformation << endl;
    else
    {
        cout<<-1;
    }
    
    return 0;
}
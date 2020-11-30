#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
bool visited[100001];
int color[100001];
void dfs(int node,int clr,vector<int> adj[])
{
    visited[node]=true;
    color[node]=clr;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!visited[child])
        dfs(child,clr^1,adj);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n;
        cin>>n;
        vector<int> adj[100001];
        set<int> arr;
        rep(i,n)
        {
            int a,b;
            cin>>a>>b;
            arr.insert(a);
            arr.insert(b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            visited[a]=false;
            visited[b]=false;
            color[a]=-1;
            color[b]=-1;
        }
        std::set<int>::iterator it=arr.begin();
        for(;it!=arr.end();it++)
        if(!visited[*it])
        dfs(*it,1,adj);
        int ans=0;
        int ans2=0;
        it=arr.begin();
        for(;it!=arr.end();it++)
        {
            int el=color[*it];
            if(el==1)
            ans++;
            else
            ans2++;
        }
        // for(int i=1;i<=n+1;i++)
        // cout<<color[i]<<" ";
        // cout<<ans<<endl;
        cout<<"Case "<<k+1<<": "<<max(ans,ans2)<<endl;
    }
    return 0;
}
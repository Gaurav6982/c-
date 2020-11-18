#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int a=0;
void dfs(int n,vector<bool>& visited,vector<vector<int> >& adj)
{
    visited[n]=true;
    a++;
    for(int i=0;i<adj[n].size();i++)
    {
        if(!visited[adj[n][i]])
        {
            dfs(adj[n][i],visited,adj);
        }
    }
    // return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > adj(n+1,vector<int>());
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visited(n+1,false);
        ll ans=1;
        int nums=0;
        for(int i=1;i<=n;i++)
        {
            a=0;
            if(!visited[i])
            {
                nums++;
                dfs(i,visited,adj);
                ans=((ans%mod)*(a)%mod)%mod;
            }
        }
        cout<<nums<<" "<<ans<<endl;
    }
    return 0;
}
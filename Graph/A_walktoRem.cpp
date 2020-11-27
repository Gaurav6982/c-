#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int j=i;j<n;j++)

using namespace std;
vector<int> adj[1000001];
vector<int> trans[1000001];
bool visited[1000001];
vector<int> SSC;
vector<int> order;
void dfs1(int n){
    visited[n]=true;
    for(int i=0;i<trans[n].size();i++)
    {
        int child=trans[n][i];
        if(!visited[child])
        dfs1(child);
    }
    SSC.push_back(n);
}
void dfs(int node)
{
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!visited[child])
        dfs(child);
    }
    order.push_back(node);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int n,m;
        cin>>n>>m;
        SSC.clear();
        order.clear();
        for(int i=0;i<=n;i++) adj[i].clear(),trans[i].clear(),visited[i]=false;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            trans[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        if(!visited[i])
        dfs(i);
        rep(0,n+1) visited[j]=false;
        int ans[n+1];
        for(int i=1;i<=n;i++) ans[i]=0;
        reverse(order.begin(),order.end());
        for(int i=0;i<order.size();i++)
        {
            int a=order[i];
            if(!visited[a])
            {
            SSC.clear();
            dfs1(a);
            if(SSC.size()<=1) continue;
                for(int i=0;i<SSC.size();i++)
                {
                    ans[SSC[i]]=1;
                }
            }
        }
        // cout<<ans<<endl;
        rep(1,n+1) cout<<ans[j]<<" ";
    return 0;
}
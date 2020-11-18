#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<vector<int> > adj;
void dfs(int val,vector<bool>& visited)
{
    visited[val]=true;

    for(int i=0;i<adj[val].size();i++)
    {
        if(!visited[adj[val][i]])
        dfs(adj[val][i],visited);
    }
}

void addEdge(int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    adj.push_back(vector<int>());
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
    }
    vector<bool> visited(n+1,false);
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            ans.push_back(i);
            dfs(i,visited);
        }
    }
    // for(int i=0;i<ans.size();i++)
    // cout<<ans[i]<<" ";
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++)
    cout<<ans[i]<<" "<<ans[i+1]<<endl;
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[16];
vector<int> trans[16];
vector<int> order;
vector<int> SSC;
bool visited[16];
void dfs1(int node)
{
    visited[node]=true;
    for(int i=0;i<trans[node].size();i++)
    if(!visited[trans[node][i]])
    dfs1(trans[node][i]);
    SSC.push_back(node);
}
void dfs(int node){
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++)
    if(!visited[adj[node][i]])
    dfs(adj[node][i]);
    order.push_back(node);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
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
    reverse(order.begin(),order.end());
    for(int i=0;i<=n;i++) visited[i]=false;
    int c=0;
    int d=0;
    for(int i=0;i<order.size();i++)
    {
        SSC.clear();
        if(!visited[order[i]])
        dfs1(order[i]);
        if(SSC.size()%2==0)
        d+=SSC.size();
        else
        {
            c+=SSC.size();
        }
        
    }
    cout<<c-d<<endl;
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[100];
bool vis[100]={false},in[100],low[100];
int timer;//golbal variable initiallized as 0;
void dfs(int node,int parent)
{
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;

    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(child==parent) continue;
        if(vis[child])
        {
            //backedge
            low[node]=min(low[node],in[child]);
        }
        else
        {
            //forward edge
            dfs(child,node);

            if(low[child]>=in[node])
            cout<<node<<" - "<<child<<" is a bridge"<<endl;

            low[node]=min(low[node],low[child]);
        }
        
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
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    return 0;
}

/*
    4 4
    1 2
    2 3
    2 4
    3 4
*/

/*
4 3
2 1
2 3
2 4
*/

/*
4 3
1 2
1 3
1 4
*/
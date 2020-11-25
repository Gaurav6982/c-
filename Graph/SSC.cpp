#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        SSC.clear();
        order.clear();
        for(int i=0;i<n;i++) adj[i].clear(),trans[i].clear(),visited[i]=false;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            adj[i].push_back((i+temp+1)%n);
            trans[(i+temp+1)%n].push_back(i);
        }
        for(int i=0;i<n;i++)
        if(!visited[i])
        dfs(i);
        rep(i,n) visited[i]=false;
        int ans=0;
        reverse(order.begin(),order.end());
        for(int i=0;i<order.size();i++)
        {
            int a=order[i];
            if(!visited[a])
            {
            SSC.clear();
            dfs1(a);
            if(SSC.size()==1 && SSC[0]!=adj[SSC[0]][0]) continue;
            ans+=SSC.size();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
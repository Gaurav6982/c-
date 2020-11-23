#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[10001];
int in[10001];
vector<int> res;
void topo(int n)
{
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);

    while(!q.empty())
    {
        int node=q.top();
        res.push_back(node);
        q.pop();
        for(int i=0;i<adj[node].size();i++)
        {
            int child=adj[node][i];
            in[child]--;
            if(in[child]==0) q.push(child);
        }
    }
    if(res.size()==n)
    {
        rep(i,res.size()) cout<<res[i]<<" ";
    }
    else
    cout<<"Sandro fails.";
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
        in[b]++;
    }
    topo(n);
    return 0;
}
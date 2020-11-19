#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<int> adj[1000001];
int visited[1000001];
int cc[1000001];
void dfs(int node,int c)
{
    visited[node]=1;
    cc[node]=c;
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(!visited[child])
        {
            dfs(child,c);
        }
    }
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
        for(int i=1;i<=n;i++) adj[i].clear(),visited[i]=0;
        vector<pair<int,int> > unequal_pairs;
        while(m--)
        {
            int x1,x2;
            char r;
            cin>>x1;
            cin>>r;
            char temp;
            if(r=='!')
            cin>>temp;
            cin>>x2;
            if(r=='=')
            {
                adj[x1].push_back(x2);
                adj[x2].push_back(x1);
            }
            else
            {
                unequal_pairs.push_back({x1,x2});
            }
        }
        bool yes=true;
        int c=1;
        for(int i=1;i<=n;i++)
        {
            
            if(!visited[i])
            {
                dfs(i,c);
                c++;
            }

        }
        for(int i=0;i<unequal_pairs.size();i++)
        {
            int x=unequal_pairs[i].first;
            int y=unequal_pairs[i].second;
            
            if(cc[x]==cc[y])
            {
                yes=false;
                break;
            }
        }
       
        if(yes)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
    }
    return 0;
}
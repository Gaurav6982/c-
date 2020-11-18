#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
// #define {a,b} make_pair(a,b)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n+1,vector<int>());
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> visited(n+1,-1);
    queue<int > q;//first= element second=parent
    q.push(1);
    bool found=false;
    // int ans=0;
    visited[1]=0;
    while(!q.empty())
    {
        int val=q.front();
        // int parent=q.front().second;
        q.pop();
        
        // visited[val]=parent;
        
        for(int i=0;i<adj[val].size();i++)
        {
            if(visited[adj[val][i]]==-1)
            {
                visited[adj[val][i]]=val;
                q.push(adj[val][i]);
                if(adj[val][i]==n)
                {
                    found=true;
                    break;
                }
            }
        }
    }
    // rep(i,n+1) cout<<visited[i]<<" "; cout<<endl;
    if(found)
    {
        vector<int> sq;
        int ans=n;
        while(visited[ans]!=0)
        {
            sq.push_back(ans);
            ans=visited[ans];
        }
        sq.push_back(1);
        reverse(sq.begin(),sq.end());
        cout<<sq.size()<<endl;
        rep(i,sq.size()) cout<<sq[i]<<" "; cout<<endl;
    }
    else
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
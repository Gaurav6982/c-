#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<vector<int> > adj(8);
bool visited[8];
void dfs(int val)
{
    visited[val]=true;

    for(int i=0;i<adj[val].size();i++)
    {
        if(visited[adj[val][i]]==false)
        dfs(adj[val][i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v=7;
    adj[1].push_back(3);
    adj[1].push_back(2);
    adj[3].push_back(1);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[2].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(2);
    adj[5].push_back(6);
    adj[6].push_back(5);
    int num_of_connected_components=0;
 
    rep(i,v+1) visited[i]=false;
    for(int i=1;i<=v;i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
            num_of_connected_components++;
        }
    }
    cout<<num_of_connected_components;
    return 0;
}

/*
    1 - 2       5 - 6         7 
    |   |  
    3 - 4
*/
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<vector<int> > adj(7);
void dfs_using_recursion(int val,bool visited[])
{
    if(visited[val])
    return;
    visited[val]=true;
    cout<<val<<" ";
    for(int i=0;i<adj[val].size();i++)
    {
        dfs_using_recursion(adj[val][i],visited);
    }
}
void dfs_using_stack(int val)
{
    stack<int> s;
    s.push(val);
    bool visited[7]={false};
    while(!s.empty())
    {
        int temp=s.top();
        if(!visited[temp])
        cout<<temp<<" ";
        visited[temp]=true;
        int i=-1; 
        for(i=0;i<adj[temp].size();i++)
        {
            if(!visited[adj[temp][i]])
            {
                s.push(adj[temp][i]);
                break;
            }
        }
        if(i!=-1 && i==adj[temp].size())
        s.pop();
    }
}
void dfs_using_stack1(int val)
{
    stack<int> s;
    s.push(val);
    bool visited[7]={false};
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        if(!visited[temp])
        cout<<temp<<" ";
        visited[temp]=true;
        int i=-1; 
        for(i=0;i<adj[temp].size();i++)
        {
            if(!visited[adj[temp][i]])
            {
                s.push(adj[temp][i]);
            }
        }
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(1);
    adj[3].push_back(6);
    adj[4].push_back(2);
    adj[5].push_back(2);
    adj[6].push_back(3);
    bool visited[7];
    rep(i,7) visited[i]=false;
    dfs_using_recursion(1,visited);
    cout<<endl;
    dfs_using_stack(1);
    cout<<endl;
    dfs_using_stack1(1);
    return 0;
}

/*
    1
   /  \
  2    3
 / \  /
4  5  6
*/
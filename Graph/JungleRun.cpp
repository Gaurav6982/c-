#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
char grid[31][31];
bool visited[31][31];
int dist[31][31];
int fin_i,fin_j;
int ans;
bool isValid(int x,int y,int n)
{
    if(x<0 || x>=n || y<0 || y>=n)
    return false;
    if(visited[x][y]==true)
    return false;
    if(grid[x][y]=='T')
    return false;
    return true;
}
void bfs(int x,int y,int n)
{
    int arr[4][2]={
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pair<int,int> node=q.front();
        q.pop();
        x=node.first;
        y=node.second;
        for(int i=0;i<4;i++)
        {
            int new_x=x+arr[i][0];
            int new_y=y+arr[i][1];
            // cout<<new_x<<new_y<<endl;
            if(isValid(new_x,new_y,n))
            {
                visited[new_x][new_y]=true;
                dist[new_x][new_y]=dist[x][y]+1;
                q.push(make_pair(new_x,new_y));
                if(new_x==fin_i && new_y==fin_j)
                {
                     ans=dist[new_x][new_y];
                }
            }
        }  
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int x,y;
    rep(i,n)
    {
        rep(j,n)
        {
            visited[i][j]=false;
            dist[i][j]=0;
            cin>>grid[i][j];
            if(grid[i][j]=='S')
            {
                x=i;
                y=j;
            }
            if(grid[i][j]=='E')
            {
                fin_i=i;
                fin_j=j;
            }
        }
    }
    // cout<<x<<y<<fin_i<<fin_j;
   bfs(x,y,n);
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int visited[10][10];
int dist[10][10];
bool isValid(int x,int y)
{
    if(x<1 || x>8 || y<1 || y>8 )
    return false;
    if(visited[x][y]==1)
    return false;

    return true;
}
int dx[]={2,1,2,1,-2,-1,-2,-1};
int dy[]={1,2,-1,-1,-1,-2,1,2};
int find(int srcX,int srcY,int endX,int endY){
    queue<pair<int,int> > q;
    q.push(make_pair(srcX,srcY));
        visited[srcX][srcY]=1;
        dist[srcX][srcY]=0;
        // cout<<srcX<<" "<<srcY<<" "<<endX<<" "<<endY;
        if(srcX==endX && srcY==endY) return 0;
    while(!q.empty())
    {
        pair<int,int> node=q.front();
        int x,y;
        x=node.first;
        y=node.second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];

            if(isValid(newX,newY))
            {
                // cout<<new_x<<" "<<new_y<<endl;
                dist[newX][newY]=dist[x][y]+1;
                visited[newX][newY]=1;
                q.push(make_pair(newX,newY));
                if(newX==endX && newY==endY)
                return dist[newX][newY];
            }
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
        int ini_x,ini_y,fin_x,fin_y;
        for(int i=0;i<=8;i++) for(int j=0;j<=8;j++) visited[i][j]=0,dist[i][j]=0;
        char temp;
        cin>>temp;
        ini_x=temp-'a'+1;
        cin>>temp;
        ini_y=temp-'0';
        cin>>temp;
        fin_x=temp-'a'+1;
        cin>>temp;
        fin_y=temp-'0';
        // cout<<ini_x<<" "<<ini_y<<" "<<fin_x<<" "<<fin_y<<endl;
        cout<<find(ini_x,ini_y,fin_x,fin_y)<<endl;
        // cout<<dist[fin_x][fin_y]<<endl;
    }
    return 0;
}
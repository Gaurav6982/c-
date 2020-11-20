#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
char grid[1000][1000];
pair<int,int> visited[1000][1000];
pair<int,int> visited1[1000][1000];
int dist[1000][1000]={0};
int dist1[1000][1000]={0};
int fin_i=-1,fin_j;
bool generate_and_push1(pair<int,int> node,queue<pair<int,int> >& q1,int n,int m)
{
    vector<pair<int,int> > nums;
    nums.push_back(make_pair(-1,0));
    nums.push_back(make_pair(0,-1));
    nums.push_back(make_pair(1,0));
    nums.push_back(make_pair(0,1));
    // cout<<node.first<<" "<<node.second<<endl;
    for(int i=0;i<4;i++)
    {
        int a=node.first + nums[i].first;
        int b=node.second + nums[i].second;

        if(a>=n ||a<0 || b>=m || b<0 || grid[a][b]=='#'||visited1[a][b].first!=-1)
        continue;
        
        q1.push(make_pair(a,b));
        visited1[a][b]=node;
        dist1[a][b]=dist1[node.first][node.second]+1;
        if( grid[a][b]=='M')
        {
            // cout<<a<<" "<<b<<endl;
            if(dist[fin_i][fin_j]>=dist1[a][b])
            return true;
        }
    }
    return false;
}
bool check_for_M(int n,int m){
    rep(i,n) rep(j,m){visited1[i][j]=make_pair(-1,-1);dist1[i][j]=0;}
     queue<pair<int,int> > q1;
    //  cout<<fin_i<<" "<<fin_j<<endl;
     pair<int,int> init=make_pair(fin_i,fin_j);
    q1.push(init);
    visited1[init.first][init.second]=make_pair(-2,-2);
    bool check=false;
    // int ans=0;
    while(!q1.empty())
    {
        pair<int,int> node=q1.front();
        q1.pop();
        // ans++;
        check=generate_and_push1(node,q1,n,m);
        if(check==true)
        break;
    }
    if(check)
    return false;
    else
    return true;
}
bool generate_and_push(pair<int,int> node,queue<pair<int,int> >& q,int n,int m)
{
    vector<pair<int,int> > nums;
    nums.push_back(make_pair(-1,0));
    nums.push_back(make_pair(0,-1));
    nums.push_back(make_pair(1,0));
    nums.push_back(make_pair(0,1));

    for(int i=0;i<4;i++)
    {
        int a=node.first + nums[i].first;
        int b=node.second + nums[i].second;

        if(a>=n ||a<0 || b>=m || b<0 || grid[a][b]=='#'||grid[a][b]=='M'||visited[a][b].first!=-1)
        continue;
        
        q.push(make_pair(a,b));
        visited[a][b]=node;
        dist[a][b]=dist[node.first][node.second]+1;
        if(((a==(n-1) || b==(m-1)) || (a==0 || b==0))&& grid[a][b]=='.')
        {
            fin_i=a;
            fin_j=b;
            // cout<<node.first<<" "<<node.second<<endl; 
            // cout<<fin_i<<" "<<fin_j<<endl; 
            if(check_for_M(n,m))
            return true;
        }
    }
    return false;
}
void bfs(pair<int,int> init,int n,int m)
{
    queue<pair<int,int> > q;
    q.push(init);
    visited[init.first][init.second]=make_pair(-2,-2);
    bool check=false;
    // int ans=0;
    while(!q.empty())
    {
        pair<int,int> node=q.front();
        q.pop();
        // ans++;
        check=generate_and_push(node,q,n,m);
        if(check==true)
        break;
    }
    // if(check)
    // return dist[fin_i][fin_j];
    // else 
    // return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int init_i,init_j;
    rep(i,n) rep(j,m){cin>>grid[i][j]; visited[i][j]=make_pair(-1,-1); if(grid[i][j]=='A') init_i=i,init_j=j;}
    // cout<<init_i<<" "<<init_j;
    bfs(make_pair(init_i,init_j),n,m);
    if(fin_i!=-1)
    {
        // cout<<dist[fin_i][fin_j];
        if(!check_for_M(n,m))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            // cout<<fin_i<<" "<<fin_j<<endl;
            vector<char> ans;
            int f_i=fin_i;
            int f_j=fin_j;
            while(visited[f_i][f_j].first!=-2)
            {
                int parent_i,parent_j;
                parent_i=visited[f_i][f_j].first;
                parent_j=visited[f_i][f_j].second;

                if(f_i==parent_i && parent_j==f_j-1)
                ans.push_back('R');
                else if(f_i==parent_i && parent_j==f_j+1)
                ans.push_back('L');
                else if(f_j==parent_j && parent_i==f_i-1)
                ans.push_back('D');
                else
                ans.push_back('U');
                f_i=parent_i;
                f_j=parent_j;
            }
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<endl;
            rep(i,ans.size()) cout<<ans[i]; cout<<endl;
        }
    }
    else
    {
        if((init_i==n-1 || init_j==m-1)||(init_i==0 || init_j==0))
        cout<<"YES\n0"<<endl;
        else
        cout<<"NO";

    }
    return 0;
}
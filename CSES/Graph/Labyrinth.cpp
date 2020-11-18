#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char> > grid(n);
    int initial_i,initial_j;
    rep(i,n){
        grid[i]=vector<char>(m);
        rep(j,m)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
            initial_i=i;initial_j=j;}
        }
    }
    // cout<<initial_i<<" "<<initial_j<<endl;
    vector<vector<pair<int,int> > > visited(n,vector<pair<int,int> >(m,make_pair(-1,-1)));
    visited[initial_i][initial_j]=make_pair(-2,-2);
    queue<pair<int,int> > q;
    q.push(make_pair(initial_i,initial_j));
    bool found=false;
    vector<pair<int,int> > choices;
    choices.push_back(make_pair(-1,0));
    choices.push_back(make_pair(0,-1));
    choices.push_back(make_pair(1,0));
    choices.push_back(make_pair(0,1));
    int f_i,f_j;
    while(!q.empty())
    {
        int i,j;
        i=q.front().first;
        j=q.front().second;
        q.pop();
        rep(k,4)
        {
            int possible_i=i+choices[k].first;
            int possible_j=j+choices[k].second;

            if(possible_i<0 || possible_i>=n || possible_j<0 || possible_j>=m || grid[possible_i][possible_j]=='#'||visited[possible_i][possible_j].first!=-1)
            continue;

            visited[possible_i][possible_j]=make_pair(i,j);
            q.push(make_pair(possible_i,possible_j));
            if(grid[possible_i][possible_j]=='B')
            {
                found=true;
                f_i=possible_i;
                f_j=possible_j;
                break;
            }
        }    
    }
    if(found)
    {
        cout<<"YES"<<endl;
        vector<char> ans;
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
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/
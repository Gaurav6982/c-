#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
vector<pair<ll,pair<ll,ll> > > projects;
// ll dp[10001][10001];
ll find(int i,int n,ll curr)
{
    if(i>=n)
    return 0;
    // if(dp[i][curr]!=-1)
    // return dp[i][curr];
    ll ans=0;
    if(projects[i].first>curr)
    ans=max(projects[i].second.second+find(i+1,n,projects[i].second.first),find(i+1,n,curr));
    else
    ans=find(i+1,n,curr);
    return ans;
    // return dp[i][curr]=ans;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    
    while(n--)
    {
        ll start,end,profit;
        cin>>start>>end>>profit;
        projects.push_back(make_pair(start,make_pair(end,profit)));
    }
    sort(projects.begin(),projects.end());
    // for(int i=0;i<projects.size();i++)
    // cout<<projects[i].first<<" "<<projects[i].second.first<<" "<<projects[i].second.second<<endl;
    // rep(i,10001) rep(j,10001) dp[i][j]=-1;
    cout<<find(0,projects.size(),0);
    return 0;
}
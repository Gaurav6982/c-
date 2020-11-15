#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int fill(ll* arr,int n)
{
    int* dp=new int[n];
    dp[0]=1;
    int m=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i] && dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                m=max(m,dp[i]);
            }
        }
    }
    return m;
}
int getBest(map<int,int>& candidates,int v)
{
    auto it=candidates.lower_bound(v);
    if(it==candidates.begin())
    return 0;
    it--;
    return it->second;
}
void insert(map<int,int> &candidates,int v,int adv)
{
    if(candidates[v]>=adv)
    return;
    candidates[v]=adv;
    auto it=candidates.find(v);
    it++;
    while(it!=candidates.end() && it->second<=adv)
    {
        auto temp=it;
        it++;
        candidates.erase(temp);
    }
}
int find_ans(vector<int>& v,int n)
{
    int dp[n];
    map<int,int> candidates;
    dp[0]=1;
    candidates[v[0]]=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=1+getBest(candidates,v[i]);
        insert(candidates,v[i],dp[i]);
    }
    return *max_element(dp,dp+n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    // int arr[n];
    vector<int> arr(n);
    rep(i,n) cin>>arr[i];
    cout<<find_ans(arr,n);
    return 0;
}
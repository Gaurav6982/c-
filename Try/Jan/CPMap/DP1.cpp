#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
// bool check(vector<int> arr,int i,int k)
// {
//     int even=0,odd=0;
//     for(int l=0;l<=k;l++)
//     {
//         if(arr[l]%2==0) even++;
//         else odd++;
//     }
//     return odd==even;
// }
// // map<pair<int,int> ,int> mp;
// int dp[105][105];
// int find(vector<int> arr,int i,int j,int b,int coins)
// {
//     // if(mp.find(make_pair(i,j))!=mp.end())
//     // return mp[make_pair(i,j)];
//     if(dp[i][j]!=-1)
//     // cout<<dp[i][j]<<endl;
//     return dp[i][j];

//     if((j-i+1)==2 && ((arr[i]%2==0 && arr[j]%2!=0) || (arr[j]%2==0 && arr[i]%2!=0)))
//     return 0;

    
    
//     int ans=0;
//     for(int k=i;k<j;k++)
//     {
//             if(coins+(abs(arr[k+1]-arr[k])) <=b)
//             {
//                 if(check(arr,i,k))
//                 {
//                     ans=max(1+find(arr,k+1,j,b,coins+(abs(arr[k+1]-arr[k]))),ans);
//                 }
//             }
//     }
//     // mp[make_pair(i,j)]=ans;
//     return dp[i][j]=ans;
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,b;
    cin>>n>>b;
    vector<int> arr;
    int temp;
    rep(i,n)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    // cout<<find(arr,0,n-1,b,0)<<endl;
    vector<int > precalc(n+1,0);
    vector<int> costs;
    int even=0,odd=0;
    // precalc[0]=0;

    for(int i=1;i<n+1;i++)
    {
        if(arr[i-1]%2==0)
        even++;
        else
        odd++;
        precalc[i]=precalc[i-1];
        if(even==odd)
        {
            precalc[i]++;
            if(i<n)
            costs.push_back(abs(arr[i]-arr[i-1]));
        }
        // cout<<precalc[i].first<<" "<<precalc[i].second<<endl;
    }
    sort(costs.begin(),costs.end());
    int ans=0;
    int c=0;
    rep(i,costs.size()){
        c+=costs[i];
        if(c>b)
        break;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

bool find(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    dp[i][0]=true;

    for(int i=1;i<sum+1;i++)
    dp[0][i]=false;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int sum=0;
    int arr[n];
    rep(i,n) cin>>arr[i],sum+=arr[i];
    // cout<<sum<<endl;
    
    if(sum%3==0)
    cout<<find(arr,n,sum/3)?1:0;
    else
    cout<<0;
}
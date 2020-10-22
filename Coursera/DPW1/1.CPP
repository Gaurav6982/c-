#include<bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int find(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];

    for(int i=0;i<sum+1;i++)
    dp[0][i]=INT_MAX;
    for(int i=0;i<n+1;i++)
    dp[i][0]=0;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=min(dp[i-1][j],1+dp[i][j-arr[i-1]]);
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

    int arr[]={1,3,4};

    int sum=0;
    cin>>sum;
    int n=3;
    cout<<find(arr,n,sum);
    return 0;
}
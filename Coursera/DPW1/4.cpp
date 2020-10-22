#include<bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
int dp[105][105];
using namespace std;
int find(int arr[],int arr1[],int i,int j){
    if(i<0 || j<0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    
    if(arr[i]==arr1[j])
    ans=1+find(arr,arr1,i-1,j-1);
    else 
    {
        ans=max(find(arr,arr1,i-1,j),find(arr,arr1,i,j-1));
    }
    return dp[i][j]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    rep(i,n) cin>>arr[i];
    int m;
    cin>>m;
    int arr1[m];
    rep(i,m) cin>>arr1[i];
    rep(i,105) rep(j,105) dp[i][j]=-1;
    cout<<find(arr,arr1,n-1,m-1);
}
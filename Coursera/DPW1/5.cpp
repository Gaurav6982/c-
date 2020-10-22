#include<bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
int dp[105][105][105];
using namespace std;
int find(int arr[],int arr1[],int arr2[],int i,int j,int k){
    if(i<0 || j<0 || k<0)
    return 0;
    if(dp[i][j][k]!=-1)
    return dp[i][j][k];
    int ans=0;
    
    if(arr[i]==arr1[j] && arr[i]==arr2[k])
    ans=1+find(arr,arr1,arr2,i-1,j-1,k-1);
    else 
    {
        int c1,c2,c3,c4,c5,c6;
        c1=find(arr,arr1,arr2,i-1,j,k);
        c2=find(arr,arr1,arr2,i,j-1,k);
        c3=find(arr,arr1,arr2,i,j,k-1);
        c4=find(arr,arr1,arr2,i-1,j-1,k);
        c5=find(arr,arr1,arr2,i-1,j,k-1);
        c6=find(arr,arr1,arr2,i,j-1,k-1);
        ans=max(ans,c1);
        ans=max(ans,c2);
        ans=max(ans,c3);
        ans=max(ans,c4);
        ans=max(ans,c5);
        ans=max(ans,c6);
        
    }
    return dp[i][j][k]=ans;
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
    int k;
    cin>>k;
    int arr2[k];
    rep(i,k) cin>>arr2[i];
    rep(i,105) rep(j,105) rep(l,105) dp[i][j][l]=-1;
    cout<<find(arr,arr1,arr2,n-1,m-1,k-1);
}
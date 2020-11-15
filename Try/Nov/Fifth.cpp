#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void fill(int dp[],int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i] && dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
    }
}
int find_max(int dp[],int l,int r,int n)
{
    int m=INT_MIN;
    int index=l;
    for(int i=l;i<=r;i++)
    {
        if(dp[i]>m)
        {
            m=dp[i];
            index=i;
        }
    }
    return index;
}
int find_ans(int arr[],int dp[],int n,int index,int l,int r,int ref[])
{
    int val=dp[index];
    while(dp[index]!=1 && index>=l)
    {
        index=ref[index];
        if(dp[index]==1 && ref[index]==index)
        break;
    }
    if(index<l && index>-1)
    val=val-dp[index];
    return val;

}
int m(int dp[],int n)
{
    int m=dp[0];
    for(int i=0;i<n;i++)
    {
        m=max(m,dp[i]);
    }
    return m;
}
int findans(int arr[],int dp[],int n,int l,int r)
{
    dp[0]=1;
    for(int i=1;i<r-l+1;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i] && dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    return m(dp,r-l+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q,s;
    cin>>n>>q>>s;
    int arr[n];
    rep(i,n) cin>>arr[i];
  
    // fill(dp,arr,n);
    // int m=INT_MIN;
    // rep(i,n) cout<<dp[i]<<" ";cout<<endl;
    // rep(i,n) cout<<ref[i]<<" ";cout<<endl;
    // rep(i,n) m=max(m,dp[i]);
    int last=0;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int l,r;
        l=(x+last*s-1)%n+1;
        r=(y+last*s-1)%n+1;
        if(l>r)
        {
            int temp=r;
            r=l;
            l=temp;
        }
        int dp[r-l+1];
        rep(i,r-l+1)dp[i]=1;
        int temp[r-l+1];
        for(int i=0;i<r-l+1;i++)
        {
            temp[i]=arr[i+l-1];
        }
       
        int ans=findans(temp,dp,n,l,r);
         rep(i,r-l+1) cout<<dp[i]<<" ";cout<<endl;
        rep(i,r-l+1) cout<<temp[i]<<" ";cout<<endl;
        last=ans;
        cout<<ans<<endl;
    }
    return 0;
}
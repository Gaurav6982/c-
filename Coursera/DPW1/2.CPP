#include<bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(j,n) for(int i=j;i<n;i++)

using namespace std;
int dp[1000005];
int find(int sum)
{
    if(sum==1)
    return 0;
    if(sum<0)
    return INT_MAX-1;
    if(dp[sum]!=-1)
    return dp[sum];
    int ans=INT_MAX-1;
    ans=std::min(ans,1+find(sum-1));
    if(sum%2==0)
    ans=std::min(ans,1+find(sum/2));
    if(sum%3==0)
    ans=std::min(ans,1+find(sum/3));

    return dp[sum]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    rep1(2,n+1)dp[i]=-1;
    cout<<find(n)<<endl;
    int i=n;
    vector<int> nums;
    nums.push_back(n);
    while(i!=1)
    {
        
        if(dp[i-1]+1==dp[i])
        {
            nums.push_back(i-1);
            i--;
        }
        else if(i%2==0 && i%3==0)
        {
            if(dp[i/2]<dp[i/3])
            {
                 nums.push_back(i/2);
                i=i/2;
            }
            else
            {
                nums.push_back(i/3);
                i=i/3;
            }
        }
        else if(i%2==0)
        {
            if(dp[i/2]+1==dp[i] )
            {
                nums.push_back(i/2);
                i=i/2;
            }
            else if(dp[i-1]+1==dp[i])
            {
                nums.push_back(i-1);
                i--;
            }
        }
        else if(i%3==0)
        {
            if(dp[i/3]+1==dp[i])
            {
                nums.push_back(i/3);
                i=i/3;
            }
            else if(dp[i-1]+1==dp[i])
            {
                nums.push_back(i-1);
                i--;
            }
        }
    }
    for(int i=nums.size()-1;i>=0;i--)
    cout<<nums[i]<<" ";
}
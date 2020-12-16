#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void subset_sum(int arr[],int sum)
{
    if(sum<10)
    {
        cout<<sum<<endl;
        return;
    }
    bool dp[10][sum+1];
    rep(i,10) rep(j,sum+1) dp[i][j]=false;
    rep(i,10) dp[i][0]=true;
    // rep(i,sum+1) dp[0][i]=true;
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]|| dp[i-1][j-arr[i-1]];
            }
        }
    }

    // for(int i=0;i<10;i++)
    // {
    //     for(int j=0;j<sum+1;j++)
    //     {
    //         cout<<dp[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }

    if(dp[9][sum]==0)
    cout<<-1<<endl;
    else
    {
        set<int> ans;
        int num=9;
        while(sum>0)
        {
            num=9;
            while(num>sum || dp[num][sum]==0 || ans.find(num)!=ans.end())
            {
                num--;
            }
            ans.insert(num);
            sum=sum-num;
            // num=9;
        }
        // reverse(ans.begin(),ans.end());
        // for(int i=0;i<(int)ans.size();i++)
        std::set<int>::iterator it= ans.begin();
        for(;it!=ans.end();it++)
        cout<<(*it);
        cout<<endl;
    }
    

    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[9];
        for(int i=1;i<=9;i++) arr[i-1]=i;
        // for(int i=0;i<9;i++) cout<<arr[i]<<" ";

        if(n>45)
        cout<<-1<<endl;
        else
        subset_sum(arr,n);
        
    }
    return 0;
}
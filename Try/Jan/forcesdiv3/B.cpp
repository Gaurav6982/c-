#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
bool check(vector<int> arr,int n,int sum)
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
            dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr;
        // int num_two=0,num_one=0;
        int sm=0;
        rep(i,n){
            int temp;
            cin>>temp;
            // if(temp==1)
            // num_one++;
            // else
            // num_two++;
            arr.push_back(temp);
            sm+=temp;
        }
        if(sm%2!=0)
        cout<<"NO"<<endl;
        else
        {
            if(check(arr,n,sm/2))
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        
        /// cout<<num_one<<" "<<num_two<<endl;
        // if(num_two%2==0 && num_one%2==0)
        // cout<<"YES"<<endl;
        // else
        // cout<<"NO"<<endl;
    }
    return 0;
}
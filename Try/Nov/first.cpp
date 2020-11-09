#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
bool* fill(int arr[],int n,int sum,bool ty[])
{
    bool dp[n+1][sum+1];
    for(int i=0;i<sum+1;i++)
    dp[0][i]=false;
    for(int i=0;i<n+1;i++)
    dp[i][0]=true;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<sum+1;i++)
    ty[i]=dp[n][i];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    // t=rand()%10+1;
    // t=5;
    // cout<<t<<endl;
    while(t--)
    {
        int n;
        // n=rand()%10+1;
        cin>>n;
        // cout<<n<<endl;
        // int temp=rand()%5+1;
        // cout<<temp<<endl;
        int sum=0;
        int arr[n];
        
        rep(i,n){cin>>arr[i];sum+=arr[i];}
        // vector<vector<bool> > dp;
        bool ty[sum+1];
        fill(arr,n,sum,ty);
        int i;
        for(i=sum/2;i<sum+1;i++)
        if(ty[i]==true && ty[sum-i]==true) break;

        cout<<max(i,sum-i)<<endl;
    }
    return 0;
}


/*
 int n=rand()%10+1;
        int arr[n];
        for(int i=0;i<n;i++)
        arr[i]=rand()%100+1;
        sort(arr,arr+n);
        cout<<"================="<<endl;
        cout<<n<<endl;
        rep(i,n)
        cout<<arr[i]<<" ";
        cout<<endl;
*/
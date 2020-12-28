#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define ENDL endl
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int find_lis(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int temp_sum=arr[i];
        for(int j=i+1;j<n;j++)
        {
            temp_sum+=arr[j];
            sum=max(sum,temp_sum);
        }
        sum=max(sum,temp_sum);
    }
    // int sum1=0;
    // for(int i=n-1;i>=0;i--)
    // {
    //     int temp_sum=arr[i];
    //     for(int j=0;j<i;j++)
    //     {
    //         temp_sum+=arr[j];
    //         sum1=max(sum1,temp_sum);
    //     }
    //     sum1=max(sum1,temp_sum);
    // }
    return sum;
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
        int arr[n];
        rep(i,n) cin>>arr[i];
        int m;
        cin>>m;
        int arr1[m];
        rep(i,m) cin>>arr1[i];
        // cout<<"here"<<endl;
        int sum=find_lis(arr,n);
        int sum1=find_lis(arr1,m);
        cout<<sum<<" "<<sum1<<endl;
// cout<<"here1"<<endl;
        if(sum<0 && sum1 <0)
        cout<<0<<endl;
        else if(sum<0 || sum1<0)
        cout<<max(sum,sum1)<<endl;
        else
        cout<<sum+sum1<<endl;
    }
    return 0;
}
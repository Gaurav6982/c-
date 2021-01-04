#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll max_sum;
void find(vector<int> arr,int n,ll all)
{
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;)
        {
            sum+=arr[j];
            j+=arr[j];
        }
        max_sum=max(sum,max_sum);
        if(sum>=all-sum)
        break;
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
        max_sum=0;
        int n;
        cin>>n;
        ll a;
        vector<int> arr;
        ll sum=0;
        rep(i,n)
        {
            cin>>a;
            sum+=a;
            arr.push_back(a);
        }

        find(arr,n,sum);

        cout<<max_sum<<endl;

    }
    return 0;
}
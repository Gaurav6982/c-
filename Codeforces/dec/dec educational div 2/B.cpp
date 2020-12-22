#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll sum=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sum=0;
        int n;
        cin>>n;
        ll arr[n];
        ll temp[n];
        rep(i,n) {cin>>arr[i];sum+=arr[i];}
        // find(arr,n,0,temp);
            ll sum1=0,sum2=0;
        rep(i,n)
        {
            if(i%2==0)
            {
            // cout<<"1 ";
                sum1+=arr[i]-1;
            }
            if(i%2!=0)
            {
            // cout<<"1 ";
                sum2+=arr[i]-1;
            }
            
        }
        if(2*sum1<sum)
        {
            rep(i,n)
            {
                if(i%2==0)
            {
            cout<<"1 ";
                // sum1++;
            }
            else
            {
                cout<<arr[i]<<" ";
                // sum1+=arr[i];
            }
            }
        }
        else
        {
            rep(i,n)
            {
                if(i%2!=0)
            {
            cout<<"1 ";
                // sum1++;
            }
            else
            {
                cout<<arr[i]<<" ";
                // sum1+=arr[i];
            }
            }
        }
        
        cout<<endl;
    }
    return 0;
}
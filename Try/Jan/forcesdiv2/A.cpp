#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll x;
        cin>>n>>x;

        ll mn=0,mx=0;

        ll arr[n];
        rep(i,n){
            cin>>arr[i];
            mx+=ceil((double)arr[i]/x);
        }

        rep(i,n)
        {
            if(arr[i]%x==0)
            {
                mn+=arr[i]/x;
                continue;
            }
            int j=i+1;
            ll sum=arr[i];
            while(j<n)
            {
                if(arr[j]%x==0)
                break;
                
                sum+=arr[j];
                if(sum%x==0)
                break;
                j++;
            }
            mn+=ceil((double)sum/x);
            i=j;
        }

        cout<<mn<<" "<<mx<<endl;

    }
    return 0;
}
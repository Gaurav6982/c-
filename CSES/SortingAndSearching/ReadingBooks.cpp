#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    ll ma=0;
    ll sum=0;
    rep(i,n)
    {
        cin>>arr[i];
        sum+=arr[i];
        ma=max(ma,arr[i]);
    }
    if(sum-ma<ma)
    cout<<ma*2;
    else
    cout<<sum;

    return 0;
}
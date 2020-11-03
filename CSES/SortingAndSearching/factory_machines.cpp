#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
bool check(ll arr[],ll n,ll mid,ll t)
{
    ll sum=0;
    rep(i,n)
    {
        sum+=mid/arr[i];
    }
    if(sum>=t)
    return true;
    else
    return false;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t;
    cin>>n>>t;
    ll arr[n];
    ll min_time=INT_MAX;
    rep(i,n)
    { 
        cin>>arr[i];
        min_time=min(min_time,arr[i]);
    }
   ll start=min_time;
   ll end=min_time*t;
   while(start<end)
    {
        ll mid=start+(end-start)/2;
        bool temp=check(arr,n,mid,t);
        if(temp)
        {
            end=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<end;
    return 0;
}
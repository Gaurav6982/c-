#include<bits/stdc++.h>
#include <iostream>
#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll power(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            ans=(ans*a)%mod;
            b--;
        }
        else
        {
            a=(a*a)%mod;
            b/=2;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    
    cin>>a;
    int n=a.size();
    unordered_map<char,int> occ;
    for(int i=0;i<n;i++)
    {
        occ[a[i]]++;
    }
    ll fact[1000001];
    fact[0]=fact[1]=1;
    for(int i=2;i<1000001;i++)
    fact[i]=((i%mod)*(fact[i-1]%mod))%mod;

    ll ans=fact[n];
    
    // cout<<ans<<endl;
    for(auto i:occ)
    {
        ans=((ans%mod)*(power(fact[i.second],mod-2)%mod))%mod;
    }
    cout<<ans;
    return 0;
}
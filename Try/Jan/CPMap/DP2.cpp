#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
map<ll,ll> storage;
ll find(ll n)
{
    if(n==0)
    return 0;
    if(n<=9)
    return 1;
    if(storage.find(n)!=storage.end())
    return storage[n];
    set<int> digits;
    ll temp=n;
    while(temp>0)
    {
        digits.insert(temp%10);
        temp/=10;
    }

    // std::set<int>::iterator it=digits.begin();
    std::set<int>::iterator lar=digits.end();
    lar--;
    // if((*it)==0)
    // it++;
    ll ans=LONG_MAX;
    // for(;it!=digits.end();it++)
    // {
        // ans=min(ans,find(n-(*it))+1);
    // }
    ans=1+find(n-*lar);

    return storage[n]=ans;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    cout<<find(n);
    return 0;
}
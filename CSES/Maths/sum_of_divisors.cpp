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
    ll sum=0;
    for(int j=1;j<=n;j++)
    {    
        sum+=((j%mod)*((n/j)%mod))%mod;
    }
    cout<<sum%mod<<endl;
}
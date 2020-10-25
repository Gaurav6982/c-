#include<bits/stdc++.h>

#define ll long long
#define Mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll power(ll a,ll b,ll mod)
{
    if(b==0)
    return 1;
    ll res=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            res=((res%mod)*(a%mod))%mod;
            b--;
        }
        else
        {
            a=((a%mod)*(a%mod))%mod;
            b=b/2;
        }
    }
    return res%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    while(n--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans=power(b,c,Mod-1);
        ans=power(a,ans,Mod);
        cout<<ans%Mod<<endl;
    }
}

//fermat theroom 
/*
Fermat therom 

(a^(p-1)) % p = 1;
*/
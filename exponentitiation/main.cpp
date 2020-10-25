#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll find(ll a,ll b)
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
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<find(a,b)<<endl;
    }
}
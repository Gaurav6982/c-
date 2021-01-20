#include<bits/stdc++.h>

#define ll long long
#define endl '\n'

#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return (a / gcd(a, b)) * b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll l=1;
        for(int i=2;i<=n;++i)
        {
            l=lcm(l,i);
        }
        ll l1=0;
        for(int i=1;i<=n;i++)
        {
            l1+=gcd(i,l);
        }
        cout<<l1<<" "<<l<<endl;
    }
    return 0;
}
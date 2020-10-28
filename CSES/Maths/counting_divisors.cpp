#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll divi[1000005];
    for(ll i=1;i<1000005;i++)
    {
        for(ll j=i;j<1000005;j+=i)
        {
            divi[j]++;
        }
    }
    ll n;
    cin>>n;
    while(n--)
    {
        ll q;
        cin>>q;
        cout<<divi[q]<<endl;
    }
    return 0; 
}
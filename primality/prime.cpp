#include <bits\stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y;
    cout<<"Enter range"<<endl;
    cin>>x>>y;
    for(ll i=x;i<=y;i++)
    {
        ll j=2;
        for(;j*j<=i;j++)
        {
            if(i%j==0)
            break;
        }
        if(j*j>i)
        cout<<i<<endl;
    }
    
}
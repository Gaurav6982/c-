#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll sum=a+b+c;
        ll m=min(a,min(b,c));
        ll x=sum/7;
        if(x>m|| sum<9)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sum=sum-3*x;
        if(sum%6==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
    }
    return 0;
}
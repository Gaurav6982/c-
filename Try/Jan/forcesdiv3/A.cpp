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
        int w,h;
        ll n;
        cin>>w>>h>>n;
        ll f=1,s=1;
        while(w%2==0)
        {
            w/=2;
            f=f*2;
        }
        while(h%2==0)
        {
            h/=2;
            s=s*2;
        }

        if(s*f>=n)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
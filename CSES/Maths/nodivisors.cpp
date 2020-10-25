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
        ll n;
        cin>>n;
        int ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ans++;
                if(i*i!=n)
                ans++;
            } 
        }
        cout<<ans<<endl;
    }
}
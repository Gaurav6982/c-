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
        int a,b;
        cin>>a>>b;
        int ans=0;
        ans+=min(a,b)*2;
        int rem=abs(a-b);
        ans+=(rem-1)*2+1;
        if(a==b)
        ans=a*2;
        else if(a==0 && b==0)
        ans=0;
        cout<<ans<<endl;
    }

    return 0;
}
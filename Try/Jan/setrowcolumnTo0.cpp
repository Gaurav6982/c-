#include<bits/stdc++.h>

#define ll long long
#define endl '\n'

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
        bool yes=false;
        if(n&1>0)
        {
            yes=true;
        }
        else
        {
            int count=0;
            while(n)
            {
                n=n&(n-1);
                count++;
                if(count>1)
                break;
            }
            if(count!=1)
            yes=true;
        }
        
        if(yes)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}
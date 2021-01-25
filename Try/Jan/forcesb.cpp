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
    for(int i=0;i<t;i++)
    {
        int d;
        cin>>d;
        long long ans;
        long long first=1,sec=1;
        for(int j=d+1;;j++)
        {
            int prime=1;
            for(int k=2;k*k<=j;k++)
            {
                if(j%k==0)
                {
                    prime=0;
                    break;
                }
            }
            if(prime)
            {
                first=j;
                break;
            }
        }
        // cout<<first;
        for(int j=first+d;;j++)
        {
            int prime=1;
            for(int k=2;k*k<=j;k++)
            {
                if(j%k==0)
                {
                    prime=0;
                    break;
                }
            }
            if(prime)
            {
                sec=j;
                break;
            }
        }
        // cout<<" "<<sec<<endl;
        ans=min(first*sec,first*first*first);
        cout<<ans<<endl;
    }
    return 0;
}
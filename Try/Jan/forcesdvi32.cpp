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
        int n;
        cin>>n;
        int x=0;
        bool yes=false;
        while(n>=2021*x)
        {
            if((n-2021*x)%2020==0)
            {
                yes=true;
                break;
            }
            x++;
        }
        if(yes)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
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
        int n;
        cin>>n;
            vector<ll> left,right;
        rep(i,n)
        {
            int m;
            cin>>m;
            rep(j,m)
            {
                ll temp;
                cin>>temp;
                if(temp<0)
                left.push_back(temp);
                else
                right.push_back(temp);
            }
        }
        cout<<left.size()*right.size()<<endl;
    }
    
    return 0;
}
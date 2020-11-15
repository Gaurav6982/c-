#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    rep(i,n) cin>>arr[i];
    stack<pair<int,int> > s;
    vector<int> ans;

    for(int i=n-1;i>-1;i--)
    {
        if(s.empty())
        ans.push_back(0);
        else if(s.top().first>arr[i])
        ans.push_back(ans[n-1-s.top().second]+1);
        else
        {
            while(!s.empty() && s.top().first<=arr[i])
            s.pop();
            ans.push_back(s.empty()?0:ans[n-1-s.top().second]+1);
        }
        s.push(make_pair(arr[i],i));
    }
    reverse(ans.begin(),ans.end());
    rep(i,n) cout<<ans[i]<<" ";cout<<endl;
    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     int a;
    //     cin>>a;
    //     cout<<ans[a-1]<<endl;
    // }

    return 0;
}

/*
8
3 4 2 7 5 8 10 6 
 
*/
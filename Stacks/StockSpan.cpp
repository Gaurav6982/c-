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
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        ans.push_back(1);
        else if(s.top().first>arr[i])
        ans.push_back(i-s.top().second);
        else
        {
            while(!s.empty()&& s.top().first<arr[i])
            s.pop();
            ans.push_back(s.empty()?1:i-s.top().second);
        }
        s.push(make_pair(arr[i],i));
    }
    // reverse(ans.begin(),ans.end());
    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
7
100 80 60 70 60 75 85
*/
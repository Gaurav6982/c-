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
    map<int,int> freq;
    rep(i,n){cin>>arr[i];freq[arr[i]]++;}
    
    stack<int> s;
    vector<int> ans;
    // ans.push_back(-1);
    // s.push(arr[n-1]);
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        ans.push_back(-1);
        else if(freq[s.top()]>freq[arr[i]])
        {
            ans.push_back(s.top());
        }
        else
        {
            while(!s.empty()&&freq[s.top()]<=freq[arr[i]])
            s.pop();
            ans.push_back(s.empty()?-1:s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

/*
10
1 1 1 2 2 2 2 11 3 3
*/
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
        vector<ll> nums;
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            nums.push_back(temp);
        }
        int i=0;
        int j=n-1;
        while(i<j)
        {
            cout<<nums[i]<<" "<<nums[j]<<" ";
            i++;
            j--; 
        }
        if(n%2!=0)
        cout<<nums[i];
        cout<<endl;
    }
    return 0;
}
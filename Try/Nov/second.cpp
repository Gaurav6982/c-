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
        int arr[n];
        set<int> nums;
        int index[100001]={0};
        rep(i,n)
        {
            cin>>arr[i];
            nums.insert(arr[i]);
        }
        int i=nums.size();
        std::set<int>::iterator el=nums.begin();
        for(;el!=nums.end();el++)
        {
            index[*el]=i--;
        }

        rep(i,n)
        cout<<index[arr[i]]<<" ";
        cout<<endl;

    }
    return 0;
}
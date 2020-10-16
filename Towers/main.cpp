#include<bits/stdc++.h>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<long long> arr;
    vector<long long> store;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        std::vector<long long>::iterator upper=upper_bound(store.begin(),store.end(),arr[i]);
        if(upper==store.end())
        {
            store.push_back(arr[i]);
        }
        else
        {
            int pos=upper-store.begin();
            store[pos]=arr[i];
        }
        int size=store.size();
        ans=std::max(ans,size);
    }
    
    cout<<ans;
}
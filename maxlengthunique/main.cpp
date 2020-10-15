#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    long long arr[n];
    set<long long> max;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        long long el;
        cin>>el;
        arr[i]=el;
    }
    int j=-1;
    for(int i=0;i<n;i++)
    {
        while(j<n-1 && !max.count(arr[j+1])) max.insert(arr[++j]);
        long long size=max.size();
        ans=std::max(ans,size);
        max.erase(arr[i]);
    }
    cout<<ans;

    return 0;
}
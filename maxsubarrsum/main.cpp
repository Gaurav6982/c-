// #include<bits\stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    long long curr=arr[0],ans=arr[0];
    for(int i=1;i<n;i++)
    {
        curr=max(curr+arr[i],arr[i]);
        ans=max(curr,ans);
    }
    cout<<ans;
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<" ";
    
}
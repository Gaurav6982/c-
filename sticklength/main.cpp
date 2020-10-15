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
    // long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        // sum+=arr[i];
    }
    // long long avg=floor(sum/n);
    sort(arr,arr+n);
    long long avg=arr[n/2];
    long long cost=0;
    for(int i=0;i<n;i++)
    {
        cost+=abs(arr[i]-avg);
    }

    cout<<cost;

   
}
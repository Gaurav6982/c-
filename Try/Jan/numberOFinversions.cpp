#include<bits/stdc++.h>

#define ll long long
#define endl '\n' 

#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int ans;
void merge(int arr[],int mid,int l,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int left[n1],right[n2];
    int j=0,k=0;
    for(int i=0;i<n1;i++)
    left[i]=arr[l+i];
    for(int i=0;i<n2;i++)
    right[i]=arr[mid+i+1];

    j=0,k=0;
    int i=l;
    while(j<n1 && k<n2)
    {
        if(left[j]>right[k])
        {
            ans+=(n1-j);
            arr[i++]=right[k++];
        }
        else
        {
            arr[i++]=left[j++];
        }
    }

    while(j<n1)
    arr[i++]=left[j++];
    while(k<n2)
    arr[i++]=right[k++];
}
void mergeSort(int arr[],int l,int r)
{
    if(l>=r) return;
    int mid=l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,mid,l,r);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    rep(i,n) cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<ans<<endl;
    // rep(i,n) cout<<arr[i]<<" ";
    return 0;
}
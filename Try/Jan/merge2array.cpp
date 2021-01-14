#include<bits/stdc++.h>

#define ll long long
#define endl '\n'

#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr1[]={1,5,9,10,15,20};
    int arr2[]={2,3,8,13};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    for(int i=0;i<n1;i++)
    {
        int j=0;
        if(arr1[i]<=arr2[j])
        continue;

        swap(arr1[i],arr2[j]);
        int temp=arr2[j];
        j++;
        while(j<n2 && temp>arr2[j])
        {
            arr2[j-1]=arr2[j];
            j++;
        }
        arr2[j-1]=temp;
    }
    rep(i,n1) cout<<arr1[i]<<" ";
    cout<<endl;
    rep(i,n2) cout<<arr2[i]<<" ";
    cout<<endl;
    return 0;
}
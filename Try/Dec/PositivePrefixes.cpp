#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int arr[1000];
int k;
bool check(int n)
{
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>0)
        cnt++;
    }
    if(cnt==k)
    return true;
    return false;
}
bool fill_arr(int n,int i)
{
    if(i-1==n)
    {
        if(check(n)) return true;
        return false;
    }
    int temp[2];
    temp[0]=i;
    temp[1]=-i;

    for(int j=0;j<2;j++)
    {
        arr[i-1]=temp[j];
        if(fill_arr(n,i+1)) return true;
        arr[i-1]=-1;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        if(fill_arr(n,1))
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
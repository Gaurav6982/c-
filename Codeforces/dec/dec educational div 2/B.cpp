#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll sum;
bool check(ll temp[],int i,int index)
{
    if(index==0)
    return true;

    if(temp[index-1]%i==0 || i%temp[index-1]==0)
    return true;
    return false;
}
void print(ll arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool check2(ll temp[],ll arr[],int n)
{
    ll sum1=0;
    for(int i=0;i<n;i++)
    sum1+=abs(temp[i]-arr[i]);
    if(2*sum1<=sum)
    return true;
    return false;
}
bool find(ll arr[],int n,int index,ll temp[])
{
    if(index==n)
    {
        if(check2(temp,arr,n))
        {
            print(temp,n);
            return true;
        }
        return false;
    }
    for(int i=1;i<=pow(10,4);i++)
    {
        if(check(temp,i,index))
        {
            temp[index]=i;
            if(find(arr,n,index+1,temp)) return true;
            temp[index]=-1;
        }
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
        cin>>n;
        ll arr[n];
        ll temp[n];
        rep(i,n) {cin>>arr[i];sum+=arr[i];}
        find(arr,n,0,temp);
         
    }
    return 0;
}
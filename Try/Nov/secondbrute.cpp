#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
bool isSafe(int arr[],int i,int ans[],int j,int num,int n)
{
    int val=arr[i];
    for(int k=val;k<n;k++)
    {
        if(ans[k]%num==0)
        return false;
    }
    return true;
}
void print_arr(int arr[],int n)
{
    rep(i,n) cout<<arr[i]<<" ";
}
bool call(int arr[],int i,int ans[],int j,int n)
{
    if(i<0)
    {
        print_arr(ans,n);
        return true;
    }

    for(int k=1;k<15;k++)
    {
        if(isSafe(arr,i,ans,j,k,n))
        {
            ans[j]=k;
            if(call(arr,i-1,ans,j-1,n)) return true;
            ans[j]=-1;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=abs(rand())%10+1;
    // cin>>t;
    cout<<t<<endl;
    while(t--)
    {
        int n;
        // cin>>n;
        cout<<"================"<<endl;
        n=abs(rand())%10+1;
        cout<<n<<endl;
        int arr[n];
        rep(i,n) arr[i]=abs(rand())%(n-i)+i+1;//cin>>arr[i];
        rep(i,n) cout<<arr[i]<<" ";
        cout<<endl;
        int ans[n];
        rep(i,n) ans[i]=-1;
        call(arr,n-1,ans,n-1,n);
        cout<<endl;
    }
    return 0;
}
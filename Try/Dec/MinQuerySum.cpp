#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int st[400001];
void fill(int arr[],int ss,int se,int si){
    if(se==ss)
    {
    st[si]=arr[se];
    return;
    }
    // cout<<"here"<<endl;
    int mid=(ss+se)/2;

    fill(arr,ss,mid,si*2);
    fill(arr,mid+1,se,si*2+1);

    st[si]=min(st[2*si],st[2*si+1]);
}
int find(int arr[],int ss,int se,int qs,int qe,int si){
    if(ss>qe || se<qs)
    {
        return INT_MAX;
    }
    if(ss>=qs && se<=qe)
    return st[si];
    int mid=(ss+se)/2;
    int a=find(arr,ss,mid,qs,qe,2*si);
    int b=find(arr,mid+1,se,qs,qe,2*si+1);

    return min(a,b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n+1];
    rep(i,n) cin>>arr[i+1];
    int t;
    cin>>t;
    fill(arr,1,n,1);
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<find(arr,1,n,l+1,r+1,1)<<endl;
    }
    return 0;
}
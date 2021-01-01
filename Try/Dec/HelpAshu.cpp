#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll st_odd[400005];
ll st_even[400005];
void build_odd(int si,int ss,int se,ll arr[]){
    if(ss==se)
    {
        st_odd[si]=(arr[ss]%2==0)?0:1;
        return;
    }

    int mid=(se+ss)/2;

    build_odd(si*2,ss,mid,arr);
    build_odd(si*2+1,mid+1,se,arr);

    st_odd[si]=st_odd[si*2]+st_odd[si*2+1];
}
void build_even(int si,int ss,int se,ll arr[]){
    if(ss==se)
    {
        st_even[si]=(arr[ss]%2==0)?1:0;
        return;
    }

    int mid=(se+ss)/2;

    build_even(si*2,ss,mid,arr);
    build_even(si*2+1,mid+1,se,arr);

    st_even[si]=st_even[si*2]+st_even[si*2+1];
}
void update_odd(int si,int ss,int se,int qi,ll newVal,ll arr[])
{
    if(ss==se)
    {
        st_odd[si]=(arr[ss]%2==0)?1:0;
        arr[ss]=newVal;
        return;
    }

    int mid=(ss+se)/2;

    if(qi<=mid)
    update_odd(si*2,ss,mid,qi,newVal,arr);
    else 
    update_odd(si*2+1,mid+1,se,qi,newVal,arr);

    st_odd[si]=st_odd[si*2]+st_odd[si*2+1];
}
void update_even(int si,int ss,int se,int qi,ll newVal,ll arr[])
{
    if(ss==se)
    {
    st_even[si]=(arr[ss]%2==0)?0:1;
    arr[ss]=newVal;
    return;
    }

    int mid=(ss+se)/2;

    if(qi<=mid)
    update_even(si*2,ss,mid,qi,newVal,arr);
    else 
    update_even(si*2+1,mid+1,se,qi,newVal,arr);

    st_even[si]=st_even[si*2]+st_even[si*2+1];
}
int query_odd(int si,int ss,int se,int qs,int qe,ll arr[])
{
    if(ss>qe || se<qs)
    return 0;

    if(ss>=qs && se<=qe)
    return st_odd[si];

    int mid=(ss+se)/2;

    return query_odd(si*2,ss,mid,qs,qe,arr)+query_odd(si*2+1,mid+1,se,qs,qe,arr);
}
int query_even(int si,int ss,int se,int qs,int qe,ll arr[])
{
    if(ss>qe || se<qs)
    return 0;

    if(ss>=qs && se<=qe)
    return st_even[si];

    int mid=(ss+se)/2;

    return query_even(si*2,ss,mid,qs,qe,arr)+query_even(si*2+1,mid+1,se,qs,qe,arr);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    ll arr[n+1];
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    build_odd(1,1,n,arr);
    build_even(1,1,n,arr);
    int q;
    cin>>q;
    while(q--)
    {
        int a,l;
        ll r;
        cin>>a>>l>>r;
        if(a==0)
        {
            // arr[l]=r;
            if(r%2!=arr[l]%2)
            {
                update_even(1,1,n,l,r,arr);
                update_odd(1,1,n,l,r,arr);
                 cout<<"update"<<endl;
                rep(i,n) cout<<arr[i+1]<<" ";
                cout<<endl;
            }
           
        }
        else if(a==1)
        {
            cout<<query_even(1,1,n,l,r,arr)<<endl;
        }
        else
        {
            cout<<query_odd(1,1,n,l,r,arr)<<endl;
        }

    }

    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int st[400001];
void build(int arr[],int ss,int se,int si)
{
    if(ss==se)
    {
        // cout<<ss<<endl;
        st[si]=arr[ss]%3==0?1:0;
        return;
    }

    int mid=(ss+se)/2;

    build(arr,ss,mid,si*2);
    build(arr,mid+1,se,si*2+1);

    st[si]=st[si*2]+st[si*2+1];
}

int query(int arr[],int ss,int se,int si,int qs,int qe)
{
    if(ss>qe || se<qs)
    return 0;
    if(ss>=qs && se<=qe)
    return st[si];

    int mid=(ss+se)/2;
    return query(arr,ss,mid,si*2,qs,qe)+query(arr,mid+1,se,si*2+1,qs,qe);
}
void update(int arr[],int ss,int se,int si,int qs,int qe)
{
       if(ss==se)
    {
        // cout<<ss<<endl;
        st[si]=arr[ss]%3==0?1:0;
        return;
    }

    int mid=(ss+se)/2;

    update(arr,ss,mid,si*2,qs,qe);
    update(arr,mid+1,se,si*2+1,qs,qe);

    st[si]=st[si*2]+st[si*2+1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    int arr[n];
    rep(i,n) arr[i]=0;
    // cout<<n<<endl;
    build(arr,0,n-1,0);
    // cout<<"here"<<endl;
    while (q--)
    {
        int a;
        cin>>a;
        int l,r;
        cin>>l>>r;
        if(a==0)
        {
            for(int i=l;i<=r;i++)
            arr[i]++;

            update(arr,0,n-1,0,l,r);
        }
        else
        {
            cout<<query(arr,0,n-1,0,l,r)<<endl;
        }
    }
    
    return 0;
}
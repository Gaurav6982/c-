#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
struct node{
    int ar[3];
};
node st[400001];
int lazy[400001];
void rotate(int si)
{
    int a = st[si].ar[2];
	st[si].ar[2] = st[si].ar[1];
	st[si].ar[1] = st[si].ar[0];
	st[si].ar[0] = a;
}
void build(int ss,int se,int si)
{
    if(ss==se)
    {
        st[si].ar[0]=1;
        st[si].ar[1]=0;
        st[si].ar[2]=0;
        return;
    }

    int mid=(ss+se)/2;

    build(ss,mid,si*2);
    build(mid+1,se,si*2+1);

    st[si].ar[0]=st[si*2].ar[0]+st[si*2+1].ar[0];
    st[si].ar[1]=st[si*2].ar[1]+st[si*2+1].ar[1];
    st[si].ar[2]=st[si*2].ar[2]+st[si*2+1].ar[2];
}

int query(int ss,int se,int si,int qs,int qe)
{
    if(lazy[si]!=0)
    {
        int add = lazy[si];
        lazy[si]=0;
        if(ss!=se){
            lazy[si*2]+=add;
            lazy[si*2+1]+=add;
        }
        add%=3;

        for(int i=0;i<add;i++)
        {
            rotate(si);
        }
    }
    if(ss>qe || se<qs)
    return 0;
    if(ss>=qs && se<=qe)
    return st[si].ar[0];

    int mid=(ss+se)/2;
    return query(ss,mid,si*2,qs,qe)+query(mid+1,se,si*2+1,qs,qe);
}
void update(int ss,int se,int si,int qs,int qe)
{
    if(lazy[si]!=0)
    {
        int add = lazy[si];
        lazy[si]=0;
        if(ss!=se){
            lazy[si*2]+=add;
            lazy[si*2+1]+=add;
        }
        add%=3;

        for(int i=0;i<add;i++)
        {
            rotate(si);
        }
    }
   if(ss>qe || se<qs) return;
   if(ss>=qs && se<=qe)
    {
        rotate(si);

        if(ss!=se)
        {
            lazy[si*2]++;
            lazy[si*2+1]++;
        }
        return;
    }
    
    // if(ss!=se)
    // {
        int mid=(ss+se)/2;
        update(ss,mid,si*2,qs,qe);
        update(mid+1,se,si*2+1,qs,qe);
        st[si].ar[0]=st[si*2].ar[0]+st[si*2+1].ar[0];
        st[si].ar[1]=st[si*2].ar[1]+st[si*2+1].ar[1];
        st[si].ar[2]=st[si*2].ar[2]+st[si*2+1].ar[2];
    // }
    
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
    build(1,n,1);
    // cout<<"here"<<endl;
    // for(int i=1;i<4*n+1;i++)
    // {
    //     cout<<st[i].ar[0]<<" "<<st[i].ar[1]<<" "<<st[i].ar[2]<<endl;
    // }
    while (q--)
    {
        int a;
        cin>>a;
        int l,r;
        cin>>l>>r;
        if(a==0)
        {
            // for(int i=l;i<=r;i++)
            // arr[i]++;
            
            
            update(1,n,1,l+1,r+1);
            // for(int i=1;i<4*n+1;i++)
            // {
            //     cout<<st[i].ar[0]<<" "<<st[i].ar[1]<<" "<<st[i].ar[2]<<endl;
            // }
        }
        else
        {
            cout<<query(1,n,1,l+1,r+1)<<endl;
        }
    }
    
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll odd(ll a)
{
    if(a%2==0)
    return (a-1);
    else
    return (a);
}
ll even(ll a)
{
    if(a%2==0)
    return a;
    else
    return (a-1);
}
ll add(ll a,ll b)
{
    return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b)
{
    return ((a%mod)*(b%mod))%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=25;
    // cin>>t;
    cout<<t<<endl;
    while(t--)
    {
        cout<<"=================="<<endl;
        int n;
        // cin>>n;
        n=abs(rand())%10+1;
        cout<<n<<endl;
        ll arr[n];
        int index_of_one=-1;
        rep(i,n){
            // cin>>arr[i];
            arr[i]=abs(rand())%10+1;
            cout<<arr[i]<<" ";
            if(arr[i]==1)
            index_of_one=i;
        }
        cout<<endl;
        ll ans[n];
        if(index_of_one==-1)//if 1 is not present
        {
            for(int i=0;i<n;i++)
            {
                if(i==0)
                ans[i]=even(arr[i]);
                else if(i==n-1)
                ans[i]=add(ans[i-1],odd(arr[i]));
                else
                ans[i]=add(ans[i-1],even(arr[i]));
            }
        }
        else if(index_of_one==0) // if 1 is present at start
        {
            for(int i=0;i<n;i++)
            {
                ans[i]=1;
            }
        }
        else if(index_of_one==n-1)// if 1 is present at friend
        {
            for(int i=0;i<n;i++)
            {
                if(i==0)
                ans[i]=even(arr[i]);
                else if(i==n-1)
                ans[i]=add(ans[i-1],odd(arr[i]));
                else
                ans[i]=add(ans[i-1],even(arr[i]));
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                
                if(i<n-1 && arr[i+1]==1)
                {
                    if(i==0)
                    ans[i]=odd(arr[i]);
                    else
                    {
                    ans[i]=add(ans[i-1],odd(arr[i]));
                    ans[i+1]=ans[i];
                    i++;
                    }
                }
                else
                {
                    if(i==0) ans[i]=even(arr[i]);
                    else if(i==n-1) ans[i]=add(ans[i-1],odd(arr[i]));
                    else ans[i]=add(ans[i-1],even(arr[i]));
                }
            }
        }// if 1 is present in between
        // rep(i,n) cout<<ans[i]<<" ";cout<<endl;
        
        int q;
        // cin>>q;
        q=abs(rand())%10+1;
        cout<<q<<endl;
        while(q--)
        {
            ll r;
            // cin>>r;
            r=abs(rand())%20+1;
            cout<<r<<endl;
            ll ans_minu_1;
            if(r<=n)
            {
                
                if(r==1)
                {
                    ans_minu_1=ans[0];
                    if(index_of_one!=0&& arr[0]%2!=0)
                    ans_minu_1++;
                }
                else
                {
                    
                        ans_minu_1=ans[r-2];
                        if(index_of_one!=0 && r%n-1==index_of_one)
                        {
                            if(index_of_one==-1)
                            {
                                 ans_minu_1=add(ans_minu_1,arr[r-1]);
                            }
                            else{if(arr[r-2]%2==0)
                            ans_minu_1=add(ans_minu_1,1);
                            ans_minu_1=add(ans_minu_1,1);}
                        }
                        else if(index_of_one!=0)
                        ans_minu_1=add(ans_minu_1,arr[r-1]);   
                    
                }
            }
            else
            {
                if(n==1)
                    {
                        ans_minu_1=mul(odd(arr[0]),r-1);
                        ans_minu_1=add(ans_minu_1,arr[0]);
                    }
                    else
                    {
                ans_minu_1=mul(ans[n-1],r/n);
                if(r%n==1)
                {
                    if(index_of_one!=0)
                    {
                        ans_minu_1=add(ans_minu_1,arr[0]);
                    }
                }
                else if(r%n==0)
                {
                    if(index_of_one==0)
                    {
                        ans_minu_1=ans_minu_1;
                    }
                    else
                    {
                        ans_minu_1=ans_minu_1/2;
                        ans_minu_1=add(ans_minu_1,ans[n-2]);
                        ans_minu_1=add(ans_minu_1,arr[n-1]);
                    }
                }
                else 
                {
                   ans_minu_1=add(ans_minu_1,ans[r%n-2]);
                   if(r%n-1==index_of_one)
                    {
                        if(arr[r-2]%2==0)
                        ans_minu_1=add(ans_minu_1,1);
                        ans_minu_1=add(ans_minu_1,1);
                    }
                    else if(index_of_one!=0)
                   ans_minu_1=add(ans_minu_1,arr[r%n-1]);
                   
                }
                    }
            }
            cout<<ans_minu_1<<endl;
        }
    }
    return 0;
}
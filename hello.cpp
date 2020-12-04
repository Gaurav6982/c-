#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll find_sum(int n)
{
    ll sum=0;
    if(n%2==0)
    sum=(n/2)*(n+1);
    else
    sum=((n+1)/2)*n;
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(n<=10)
        {
            if(n==k)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<i+1<<" ";
                }
                cout<<endl;
            }
            else
            {
                if(k==1)
                {
                    cout<<1<<" ";
                    for(int i=2;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                if(k==2)
                {
                    cout<<1<<" "<<2<<" ";
                    for(int i=3;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                if(k==3)
                {
                    cout<<1<<" "<<2<<" "<<-3<<" "<<4<<" ";
                    for(int i=5;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                if(k==4)
                {
                    cout<<1<<" "<<2<<" "<<3<<" ";
                    for(int i=4;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                if(k==5)
                {
                    cout<<1<<" "<<2<<" "<<3<<" "<<4<<" ";
                    for(int i=5;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                if(k==6)
                {
                    cout<<1<<" "<<2<<" "<<3<<" "<<4<<" ";
                    for(int i=5;i<=6;i++)
                    cout<<-i<<" ";
                    cout<<7<<" ";
                    for(int i=8;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                if(k==7)
                {
                    cout<<"1 2 3 4 5 ";
                    for(int i=6;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                if(k==8)
                {
                    cout<<"1 2 3 4 5 6 ";
                    for(int i=7;i<=n;i++)
                    cout<<-i<<" ";
                    cout<<endl;
                    continue;
                }
                int num=k/2;
                ll sum;
                if(k%2==0)
                sum=(k/2)*(k+1);
                else
                sum=k*((k+1)/2);
                sum=sum/2;
                ll temp_sum=num*(num+1);
                temp_sum/=2;
                while(temp_sum<sum)
                {
                    num++;
                    temp_sum=find_sum(num);
                }
                num--;
                for(int i=1;i<=num;i++)
                cout<<i<<" ";
                for(int i=num+1;i<=k;i++)
                cout<<-i<<" ";
                cout<<k+1<<" ";
                for(int i=k+2;i<=n;i++)
                cout<<-i<<" ";
                cout<<endl;
            }
        }
        else
        {
            int arr[n+1];
            for(int i=1;i<=n;i++)
            {
                if(i%2==0)
                arr[i]=i;
                else
                arr[i]=-i;
            }

            if(k==n/2)
            {
                for(int i=1;i<=n;i++)
                cout<<arr[i]<<" ";
                cout<<endl;
            }
            else if(k<n/2)
            {
                int num=n/2-k;
                int i=n;
                while(num-- && i>=1)
                {
                    arr[i]=-arr[i];
                    i-=2;
                }
                for(int i=1;i<=n;i++)
                cout<<arr[i]<<" ";
                cout<<endl;
            }
            else
            {
                int num=k-n/2;
                int i=n-1;
                while(num-- && i>=1)
                {
                    arr[i]=-arr[i];
                    i-=2;
                }

                for(int i=1;i<=n;i++)
                cout<<arr[i]<<" ";
                cout<<endl;
            }
            

        }
        
    }
    return 0;
}
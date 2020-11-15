#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int odd(int a)
{
    if(a%2==0)
    return (a-1);
    else
    return (a);
}
int even(int a)
{
    if(a%2==0)
    return a;
    else
    return (a-1);
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
        int arr[n];
        int count_all1=0;
        rep(i,n)
        {
            cin>>arr[i];
        }
       
        int ans[n];
        // calculate for first n turns
        if(arr[0]==1)
        {
            
            ans[0]=1;
            for(int i=0;i<n;i++)
            {
                if(arr[i+1]==1)
                {
                    int count_1=i==0?1:0;
                    int k=i+1;
                    while(k<n && arr[k]==1)
                    {
                        count_1++;k++;
                    }

                    if(k==n)
                    {
                        if(count_1%2==0)
                        {
                           
                            int k=i+1;
                            while(k<n&&arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                        else
                        {
                            int k=i+1;
                            while(k<n&&arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                    }
                    else
                    {
                        if(count_1%2==0)
                        {
                            int k=i+1;
                            while(k<n && arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                        else
                        {
                            int k=i+1;
                            while(k<n&&arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                    }
                }
            }


        }
        else
        {
            for(int i=0;i<n;i++)
            {
                ans[i]=0;
                if(i==n-1)
                {
                    ans[i]=ans[i-1]+odd(arr[i-1]);
                }
                else if(arr[i+1]==1)
                {
                    int count_1=0;
                    int k=i+1;
                    while(k<n && arr[k]==1)
                    {
                        count_1++;k++;
                    }

                    if(k==n)
                    {
                        if(count_1%2==0)
                        {
                            if(i==0)
                            ans[i]=odd(arr[i]);
                            else
                            ans[i]=ans[i-1]+odd(arr[i]);
                            int k=i+1;
                            while(k<n&&arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                        else
                        {
                            if(i==0)
                            ans[i]=even(arr[i]);
                            else
                            ans[i]=ans[i-1]+even(arr[i]);
                            int k=i+1;
                            while(k<n&&arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                    }
                    else
                    {
                        if(count_1%2==0)
                        {
                            if(i==0)
                            ans[i]=even(arr[i]);
                            else
                            ans[i]=ans[i-1]+even(arr[i]);
                            int k=i+1;
                            while(k<n && arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                        else
                        {
                            if(i==0)
                            ans[i]=odd(arr[i]);
                            else
                            ans[i]=ans[i-1]+odd(arr[i]);
                            int k=i+1;
                            while(k<n&&arr[k]==1)
                            {
                                ans[k]=ans[k-1];
                                if(i%2==0)
                                {
                                    if(k%2==0)
                                    ans[k]++;
                                }
                                else
                                {
                                    if(k%2!=0)
                                    ans[k]++;
                                }
                                k++;
                            }
                            i=k-1;
                        }
                    }
                }
                else
                {
                    if(i==0)
                    ans[i]=even(arr[i]);
                    else
                    ans[i]=ans[i-1]+even(arr[i]);
                }  
            }
        }
        
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int find_two(int el)
{
    int num=1;
    while(num<el)
    {
        num=num*2;
    }
    if(num!=el && num!=1)
    return num/2;
    return num;
}
void print_arr(int arr[],int n)
{
    rep(i,n) cout<<arr[i]<<" ";
    cout<<endl;
}
void copy(int temp[],int arr[],int n)
{
    for(int i=0;i<n;i++)
    temp[i]=arr[i];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n];
            int temp[n];
            int ans[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            temp[i]=arr[i];
            ans[i]=arr[i];
        }
        for(int i=0;i<x;i++)
        {
            // for(int i=0;i<n;i++)
            // arr[i]=ans[i];
            copy(arr,ans,n);
            for(int i=0;i<n;i++)
            {
                for(int  j=i+1;j<n;j++)
                {
                copy(temp,arr,n);
                    int el1=arr[i];
                    int el2=arr[j];
                    int min_val=min(el1,el2);
                    int max_p_2=find_two(min_val);
                    // cout<<max_p_2<<endl;
                    // cout<<"El1 "<<el1<<" EL2 "<<el2<<" max2 "<<max_p_2<<endl;
                    el1=el1^max_p_2;
                    el2=el2^max_p_2;
                    temp[i]=el1;
                    temp[j]=el2;
                    // print_arr(temp,n);
                    int k=0;
                    int l=0;
                    while(k<n && l<n)
                    {
                        if(temp[k]!=ans[l])
                        break;
                        k++;
                        l++;
                    }
                    if(temp[k]<ans[l])
                    {
                        copy(ans,temp,n);
                    }

                }
            }
                    print_arr(ans,n);
        }
    }
    return 0;
}
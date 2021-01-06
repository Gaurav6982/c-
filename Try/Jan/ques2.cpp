#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

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
        int arr[n];
        rep(i,n) cin>>arr[i];
        sort(arr,arr+n);

        int count=0;
        int boxes=0;
        int sum=0;
        for(int i=n-1;i>=0;)
        {
            if(sum+arr[i]<=k)
            {
                sum+=arr[i];
                if(arr[i]!=0)
                count++;
                if(sum==k)
                {
                    sum=0;
                    boxes++;
                }
                i--;
            }
            else
            {
                int j=0;
                // bool flag=false;
                for(;j<=i;j++)
                {
                    if(arr[j]+sum>=k)
                    {
                        sum=0;
                        boxes++;
                        if(arr[j]!=0)
                        count++;
                        arr[j]=0;
                        // flag=true;
                        break;
                    }
                }
                if(j==i+1)
                break;
            }
            if(boxes==2)
            break;
        }
        if(boxes!=2)
        count=-1;
        cout<<count<<endl;
    }
    return 0;
}
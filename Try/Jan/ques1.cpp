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
        int n,m;
        cin>>n>>m;
        vector<int> arr;
        vector<int> arr1;
        int temp;
        ll sum1=0,sum2=0;
        rep(i,n){
            cin>>temp;
            sum1+=temp;
            arr.push_back(temp);
        }
        rep(i,m)
        {
            cin>>temp;
            sum2+=temp;
            arr1.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        sort(arr1.begin(),arr1.end());

        int ans=0;
        int i=0;
        int j=m-1;
        while(i<n && j>=0 && sum1<sum2)
        {
            sum1+=(arr1[j]-arr[i]);
            sum2=sum2-arr1[j]+arr[i];
            i++;
            j--;
            ans++;
        }
        if(sum1<sum2)
        cout<<-1<<endl;
        else
        cout<<ans<<endl;
    }
    return 0;
}
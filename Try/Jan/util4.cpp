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
        vector<int> arr;
        int tp;
        rep(i,n)
        {
            cin>>tp;
            arr.push_back(tp);
        }
        sort(arr.begin(),arr.end());
        int sum1=0,sum2=0;
        vector<int> first,second;

        for(int i=n-1;i>=0;i--)
        {
            if(sum1<sum2 && sum1<k)
            {
                sum1+=arr[i];
                first.push_back(arr[i]);
                // i--;
            }
            else if(sum1>=sum2 && sum2<k)
            {
                sum2+=arr[i];
                second.push_back(arr[i]);
                // i--;
            }
        }
        if(sum1>=k && sum2>=k)
        cout<<first.size()+second.size()<<endl;
        else
        cout<<-1<<endl;

    }

    return 0;
}